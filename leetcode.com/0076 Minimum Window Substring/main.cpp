#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r, ns = s.length(), nt = t.length(), win_size = ns, result_idx = -1;

        unordered_map<char, int> m, cur_m;
        for (char c: t) {
            m[c]++;
            cur_m[c] = 0;
        }

        for (; l <= ns - nt && m.find(s[l]) == m.end(); ++l);

        if (m.find(s[l]) == m.end()) return "";

        cur_m[s[l]] = 1;
        int found_cnt = 1;
        for (r = l + 1; r < ns && found_cnt < nt; ++r) {
            if (m.find(s[r]) != m.end()) {
                cur_m[s[r]]++;
                if (cur_m[s[r]] <= m[s[r]]) found_cnt++;
                else if (s[r] == s[l]) {
                    cur_m[s[l++]]--;
                    while (true) {
                        if (m.find(s[l]) == m.end()) ++l;
                        else if (cur_m[s[l]] > m[s[l]]) {
                            cur_m[s[l++]]--;
                        } else break;
                    }
                }
            }
        }

        if (found_cnt < nt) return "";
        

        // 第一个满足的窗口(最左边)
        result_idx = l;
        win_size = r - l;

        // 寻找其它可能结果
        for (--r; r < ns - 1; ) {
            
            if (m.find(s[l]) != m.end()) {
                cur_m[s[l]]--;
                if (cur_m[s[l]] < m[s[l]]) {
                    found_cnt--;
                }
            }
            ++l;

            if (m.find(s[++r]) != m.end()) {
                cur_m[s[r]]++;
                if (cur_m[s[r]] <= m[s[r]]) {
                    found_cnt++;
                }
            }

            if (found_cnt == nt) {
                while (true) {
                    if (m.find(s[l]) == m.end()) ++l;
                    else if (cur_m[s[l]] > m[s[l]]) {
                        cur_m[s[l++]]--;
                    } else break;
                }
                if (r - l + 1 < win_size) {
                    result_idx = l;
                    win_size = r - l + 1;
                }
            }
        }

        return s.substr(result_idx, win_size);
    }
};



int main(int argc, char const *argv[])
{
    Solution sol;
    string s, t;
    while (cin>>s>>t)
        cout<<sol.minWindow(s, t)<<endl;
    return 0;
}
