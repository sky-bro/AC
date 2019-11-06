// 定位关键字在文本中所有出现位置
// 扫描不需要回溯，时间复杂度位O(n)，与关键字数目与长度无关
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class AC
{
private:
    int state_idx = -1;
    // index: 状态号, char(int)->int(转移到的状态号)
    vector< map<int, int> > states;
    vector<int> failures;
    vector< vector<string> > outputs;
    // 转向函数goto
    int g(int tmp_state_idx, int c) {
        if (states[tmp_state_idx].find(c) != states[tmp_state_idx].end()) {
            return states[tmp_state_idx][c];
        }
        return tmp_state_idx==0?0:-1;
    }
    // 失效函数failure
    int f(int tmp_state_idx) {
        return failures[tmp_state_idx];
    }
    // 输出函数output
    void o(int tmp_state_idx) {
        for (vector<string>::iterator it = outputs[tmp_state_idx].begin(); it != outputs[tmp_state_idx].end(); it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
public:
    // pattern->pattern_len
    AC(map<string, int> & patterns);
    void update_patterns(map<string, int> & patterns);
    ~AC();

    void print_AC_states() {

    }

    void start_match(FILE *in, FILE *out) {
        char c;
        int tmp_state_idx = 0;
        while ((c=fgetc(in)) != EOF) {
            // tmp_state_idx保存当前的状态号，idx保存下一步的状态号
            int idx = g(tmp_state_idx, c);
            while (idx == -1) {
                idx = g(f(tmp_state_idx), c);
                tmp_state_idx = idx;
            }

            if (outputs[idx].size() != 0){
                o(idx);
            }
            tmp_state_idx = idx;
        }
    }
};

// 利用广度优先遍历模式串集合的方式(顺序)进行初始化
AC::AC(map<string, int> & patterns)
{
    int add_pattern_cnt = 0;
    int total_patterns = patterns.size();

    // 首先是初始状态0
    ++state_idx;
    states.push_back(map<int, int>());
    failures.push_back(0);
    outputs.push_back(vector<string>());

    // depth = 1 的部分
    for (map<string, int>::iterator it = patterns.begin(); it != patterns.end(); ++it) {
        if (states[0].find(it->first[0]) == states[0].end()){
            // 没有已有的转移，则创建新的转移，转移到++state_idx
            states[0][it->first[0]] = ++state_idx;

            // 添加新状态（即push进其转移的map，目前为空），对应状态号state_idx
            states.push_back(map<int, int>());

            // 所有深度为1的状态值的failure值为0
            failures.push_back(0);

            // 添加新的状态的输出字符串集合（目前为空）
            outputs.push_back(vector<string>());
        }

        if (it->second == 1) {
            // 添加转移到的状态states[0][ it->first[0]的输出字符串
            outputs[ states[0][ it->first[0] ] ].push_back(it->first);
            ++add_pattern_cnt;
        }
    }

    // depth > 1 的部分
    int depth = 1;
    
    for (; add_pattern_cnt != total_patterns; ++depth) {
        for (map<string, int>::iterator it = patterns.begin(); it != patterns.end(); ++it) {
            // 如果当前的i等于当前访问字符串的长度it->second，说明该模式字符串已经扫描完毕，continue下一个串
            if (it->second <= depth) continue;

            int idx = 0;
            for (int i = 0; i < depth; ++i) {
                idx = states[idx][it->first[i]];
            }

            if (states[idx].find(it->first[depth]) == states[idx].end()){
                // 没有已有的转移，则创建新的转移，转移到++state_idx
                states[idx][it->first[depth]] = ++state_idx;

                // 添加新状态（即push进其转移的map，目前为空），对应状态号state_idx
                states.push_back(map<int, int>());

                // 所有深度为1的状态值的failure值为0
                int tmp_state_idx = failures[idx];
                while (g(tmp_state_idx, it->first[depth]) == -1)
                    tmp_state_idx = failures[tmp_state_idx];
                failures.push_back( g(tmp_state_idx, it->first[depth]) );

                // 添加新的状态的输出字符串集合（目前为空）
                outputs.push_back(vector<string>());

                // 合并f(s)的output到s
                outputs[state_idx].insert(outputs[state_idx].end(), outputs[failures[state_idx]].begin(), outputs[failures[state_idx]].end());
                // for (vector<string>::iterator it = outputs[failures[state_idx]].begin();it != outputs[failures[state_idx]].end();it++){
                //     outputs[state_idx].push_back(*it);
                // }
            }

            if (it->second == depth+1){
                outputs[ states[idx][ it->first[depth] ] ].push_back(it->first);
                ++add_pattern_cnt;
            }

        }
    }
}

AC::~AC()
{
}
