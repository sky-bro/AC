// AC w/ triple array trie (AC_TAT...)

// https://linux.thai.net/~thep/datrie/datrie.html 最好的应该是这个，英文，包括DAT和TAT
// https://blog.csdn.net/hit_fantasy/article/details/17310017
// https://blog.csdn.net/choumin/article/details/51106780 这个好
// https://www.cnblogs.com/en-heng/p/6265256.html Trie树不错，逐步深入

// 定位关键字在文本中所有出现位置
// 扫描不需要回溯，时间复杂度位O(n)，与关键字数目与长度无关

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
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
        cout<<"*base\n";
        for (auto it = base.begin(); it != base.end(); ++it) {
            cout<<*it<<"\t";
        }

        cout<<"\n\n*next\n";
        for (auto it = next.begin(); it != next.end(); ++it) {
            cout<<*it<<"\t";
        }

        cout<<"\nnext表占用: "<<max_state_idx+1<<"/"<<next.size()<<" "<<1.0*(max_state_idx+1)/next.size();

        cout<<"\n\n*check\n";
        for (auto it = check.begin(); it != check.end(); ++it) {
            cout<<*it<<"\t";
        }

        cout<<"\n\n*failures\n";
        for (auto it = failures.begin(); it != failures.end(); ++it) {
            cout<<*it<<"\t";
        }

        cout<<"\n\n*outputs\n";
        for (auto i = 0; i < outputs.size(); ++i) {
            cout<<"index "<<i<<": ";
            for (auto it2 = outputs[i].begin(); it2 != outputs[i].end(); ++it2)
                cout<<*it2<<"\t";
            cout<<endl;
        }
        cout<<endl;
    }

    void start_match(FILE *in, ostream &out) {
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
                out<<"At index: "<<char_read<<":\n\t";
                o(t);
            }

            s = t;
        }
    }

};

// 首次通过模式串构建自动机耗费时间与空间会多一些，可以将创建好后的几个数组写到文件，这样以后直接通过文件初始化会更高效
// 利用广度优先遍历模式串集合的方式(顺序)进行初始化
// 这里pair<int, vector<Pattern> >类型的first元素表示使得转移到当前状态的字符，
// second元素是当前状态的包含的模式串Pattern集合，Pattern类型中不仅含有相应字符串还有下一个要识别的字符下标
AC::AC(pair<int, vector<Pattern> > & patterns)
{
    // 首先是初始状态0
    next.push_back(0);
    check.push_back(0);
    max_state_idx=0; // 目前只有初始状态，最大状态下标是0

    // 先广搜索BFS，根节点就是传入的patterns，先广遍历的顺序也是状态号的顺序 -- 状态号从0开始
    queue< pair<int, vector<Pattern> > > q;
    q.push(patterns);

    // 状态转移公式: base[cur] + min_chr = next_idx
    int cur = 0, next_idx = 1;
    while (!q.empty()) {
        base.push_back(0);

        pair<int, vector<Pattern> > pair_iv = q.front();
        q.pop();

        // m存放孩子节点们
        map<int, vector<Pattern> > m;
        int min_chr = 255;
        // 第一遍扫描，三个任务：找到最小字符min_chr，收集统计当前状态的输出字符串，收集孩子节点到m中
        // 找最小字符min_chr主要是为了找下一个next数组的下标从哪里开始，挨着放这样可以尽可能节省空间
        vector<string> output;
        for (int i = 0; i < pair_iv.second.size(); ++i) {

            // 状态cur的输出字符串output，
            if (pair_iv.second[i].str.length() == pair_iv.second[i].idx){
                output.push_back(pair_iv.second[i].str);
                continue;
            }

            int c = pair_iv.second[i].str[ pair_iv.second[i].idx ]; // 即将读入的字符
            if (c < min_chr)
                min_chr = c;

            if (pair_iv.second[i].str.length() > pair_iv.second[i].idx) { // 该串还有字符未读入
                // 读入c后的模式串们
                if (m.find(c) != m.end()) {
                    m[c].push_back(Pattern(pair_iv.second[i].str, pair_iv.second[i].idx+1));
                } else {
                    m[c] = vector<Pattern>();
                    m[c].push_back(Pattern(pair_iv.second[i].str, pair_iv.second[i].idx+1));
                }
            }
        }
        outputs.push_back(output); // 至此当前状态cur对应的outputs初步填充，填failures时可能合并进来其它状态的outputs


        // 下面是cur状态对应的failures数组
        if (check[cur] == 0) { // check[cur]就是表示cur状态的上一状态
            failures.push_back(0); // 上一状态是0的话failures直接初始化为0
        } else {
            int last_idx = failures[check[cur]];
            while (g(last_idx, pair_iv.first) == -1) // -1表示转移失败
                last_idx = failures[last_idx];
            failures.push_back( g(last_idx, pair_iv.first) );
            // 找到cur状态对应的未来转移失败的跳转状态g(last_idx, pair_iv.first)后，可以把跳转状态的outputs值复制给当前状态
            outputs[cur].insert(outputs[cur].end(), outputs[failures[cur]].begin(), outputs[failures[cur]].end());
        }

        // 当前状态没有孩子节点了
        if (m.empty()) {
            ++cur;
            continue;
        }

        // 当前状态还有孩子节点
        // 扫描next数组，寻找下一个next下标的合适位置，要求能放下m中所有的转移字符
        // 每次从next_idx开始寻找，next_idx前的位置都已经填满
        int tmp_next_idx = next_idx;
        for (;;++tmp_next_idx){
            auto it = m.begin();
            for (; it != m.end(); ++it) {
                // 读入当前字符
                int c = it->first;
                int b = tmp_next_idx - min_chr;
                if (next[b+c]) // 一旦有一个转移字符放不下了，接着寻找下一个位置
                    break;
            }
            // 说明所有字符都能放下，找到了tmp_next_idx
            if (it == m.end())
                break;
        }

        // 更新下次开始寻找的位置next_idx, 下一次从何处开始寻找？至少第一个: next[next_idx] == 0 成立
        while (next[next_idx] != 0) {
            ++next_idx;
            if (next_idx >= next.size()) {
                // +1就够了，抠是抠了点，但是可以最大化空间效率，而且在后面一旦生成了这几个数组就可以导出数组，
                // 不通过模式串来初始化，而是用导出的数组直接读入
                next.resize(next_idx+1); 
            }
        }

        // 设置当前状态对应的base数组中存的next数组的基础偏移(真绕..但就是这个意思)
        base[cur] = tmp_next_idx - min_chr;
        // 将孩子节点放入队列，设置孩子节点对应的check数组值-->cur，next值-->孩子节点的状态号
        for (auto it=m.begin();it!=m.end();++it){
            q.push(*it);
            int i = base[cur] + it->first;
            if (i >= next.size()){
                // 同样+1就够了
                next.resize(i+1);
            }
            next[i] = ++max_state_idx;
            check.push_back(cur);
        }
        ++cur;
    }
}