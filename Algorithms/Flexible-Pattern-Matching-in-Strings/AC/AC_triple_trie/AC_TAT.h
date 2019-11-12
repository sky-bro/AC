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
#include <set>

using namespace std;

class Pattern {
public:
    string str;
    // 如果str.length()是直接获长度就不用这个Pattern了
    int len;
    

    Pattern(string buf, int length):str(buf), len(length) { }

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
    AC(set<Pattern> & patterns);
    ~AC(){}

    void print_AC_states() {

    }

    void start_match(FILE *in, FILE *out) {
        char c;
        int s = 0, t;
        while ((c=fgetc(in)) != EOF) {

            // s保存当前的状态号，t保存下一步的状态号
            t = g(s, c);
            while (t == -1) {
                s = f(s);
                t = g(s, c);
            }

            if (outputs[t].size() != 0)
                o(t);

            s = t;
        }
    }

};