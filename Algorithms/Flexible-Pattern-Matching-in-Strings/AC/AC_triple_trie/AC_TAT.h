// AC w/ triple array trie (AC_TAT...)

// https://linux.thai.net/~thep/datrie/datrie.html 最好的应该是这个，英文，包括DAT和TAT
// https://blog.csdn.net/hit_fantasy/article/details/17310017
// https://blog.csdn.net/choumin/article/details/51106780 这个好
// https://www.cnblogs.com/en-heng/p/6265256.html Trie树不错，逐步深入

// 定位关键字在文本中所有出现位置
// 扫描不需要回溯，时间复杂度位O(n)，与关键字数目与长度无关

#include <iostream>
#include <vector>
#include <map>
// #include <set>
#include <queue>

using namespace std;

class Pattern {
public:
    string str;
    // 如果str.length()是直接获长度就不用这个Pattern了
    int idx;
    

    Pattern(string buffer, int index):str(buffer), idx(index) { }

	bool operator< (const Pattern& rhs) const{
		return this->str < rhs.str;
	}
};

class AC
{
private:
    int max_state_idx = -1;

    // 旧的实现
    // index: 状态号, char(int)->int(转移到的状态号)
    // vector< map<int, int> > states; 

    // 新的实现
    // goto表现在依靠三个数组实现(原来通过Map实现，还是有些空间损失)
    vector<int> next; // 下标是base中的值--偏移
    vector<int> base; // 下标是状态
    vector<int> check; // 下标是状态

    vector<int> failures;
    vector< vector<string> > outputs;

    // 转向函数goto
    int g(int s, int c) {
        // ? 检查越界？
        if (base.size() <= s) return -1;
        int t_idx = base[s]+c;
        if (t_idx<next.size() && check[next[t_idx]] == s) {
            // 状态转移成功
            return next[t_idx];
        }
        // 状态转移失败(s是0的话，失败也就直接不算失败，反正转向0)
        return s==0?0:-1;
    }

    // 失效函数failure
    int f(int s) {
        return failures[s];
    }

    // 输出函数output
    void o(int s) {
        // 注意这里没有判断output[s]大小是否为0
        for (vector<string>::iterator it = outputs[s].begin(); it != outputs[s].end(); it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }

public:
    AC(pair<int, vector<Pattern> > & patterns);
    ~AC(){}

    void print_AC_states() {

    }

    void start_match(FILE *in, FILE *out) {
        unsigned char_read = 0;

        char c;
        int s = 0, t;
        while ((c=fgetc(in)) != EOF) {
            ++char_read;

            // s保存当前的状态号，t保存下一步的状态号
            t = g(s, c);
            while (t == -1) {
                s = f(s);
                t = g(s, c);
            }

            if (outputs[t].size() != 0){
                cout<<"At index: "<<char_read<<":\n\t";
                o(t);
            }

            s = t;
        }
    }

};

// 首次通过模式串构建自动机耗费时间与空间会多一些，可以将创建好后的几个数组写到文件，这样以后直接通过文件初始化会更高效
// 利用广度优先遍历模式串集合的方式(顺序)进行初始化
AC::AC(pair<int, vector<Pattern> > & patterns)
{
    // 首先是初始状态0
    max_state_idx=0; // 暂时没有用到？
    next.push_back(0);
    check.push_back(0);

    // depth > 1 的部分
    int depth = 0;
    queue< pair<int, vector<Pattern> > > q;
    q.push(patterns);

    // base[cur] + min_chr = next_idx
    int cur = 0, total = 0, next_idx = 1;
    while (!q.empty()) {
        base.push_back(0);

        pair<int, vector<Pattern> > pair_iv = q.front();
        q.pop();
        // m存放孩子节点们
        map<int, vector<Pattern> > m;
        int min_chr = 255;
        // 第一遍扫描，找到最小字符min_chr，收集统计当前状态的输出字符串
        vector<string> output;
        for (int i = 0; i < pair_iv.second.size(); ++i) {
            // 状态cur的输出字符串output
            if (pair_iv.second[i].str.length() == pair_iv.second[i].idx){
                output.push_back(pair_iv.second[i].str);
                continue;
            }

            int c = pair_iv.second[i].str[pair_iv.second[i].idx];
            if (c < min_chr)
                min_chr = c;

            if (pair_iv.second[i].str.length() > pair_iv.second[i].idx) { // 该串还有字符未读入
                if (m.find(c) != m.end()) {
                    m[c].push_back(Pattern(pair_iv.second[i].str, pair_iv.second[i].idx+1));
                } else {
                    m[c] = vector<Pattern>();
                    m[c].push_back(Pattern(pair_iv.second[i].str, pair_iv.second[i].idx+1));
                }
            }
        }
        outputs.push_back(output);

        if (check[cur] == 0) {
            failures.push_back(0);
        } else {
            int last_idx = failures[check[cur]];
            while (g(last_idx, pair_iv.first) == -1)
                last_idx = failures[last_idx];
            failures.push_back( g(last_idx, pair_iv.first) );
            outputs[cur].insert(outputs[cur].end(), outputs[failures[cur]].begin(), outputs[failures[cur]].end());
        }

        if (!m.size()) {
            base.push_back(-1); // 叶节点
            ++cur;
            continue;
        }

        // 扫描next数组，寻找next合适位置，
        int tmp_next_idx = next_idx;
        for (;;++tmp_next_idx){
            auto it = m.begin();
            for (; it != m.end(); ++it) {
                // 读入当前字符
                int c = it->first;
                int b = tmp_next_idx - min_chr;
                if (next[b+c])
                    break;
            }
            // 说明所有字符都能放下，找到了tmp_next_idx
            if (it == m.end())
                break;
        }
        // 下一次从何处开始寻找？至少第一个: next[next_idx] == 0 成立
        while (next[next_idx] != 0) {
            ++next_idx;
            if (next_idx >= next.size()) {
                next.resize(next_idx+1); // +1当然是够了。。可要不多加点
            }
        }

        // 放置好孩子节点们
        base[cur] = tmp_next_idx - min_chr;
        for (auto it=m.begin();it!=m.end();++it){
            q.push(*it);
            int i = base[cur] + it->first;
            if (i >= next.size()){
                next.resize(i+1);
            }
            next[i] = ++total;
            check.push_back(cur);
        }
        ++cur;
    }
}