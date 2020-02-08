#include <iostream>
#include <cstring>

using namespace std;

// ref: https://leetcode.com/problems/remove-duplicate-letters/discuss/76768/A-short-O(n)-recursive-greedy-solution

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length(); if (n == 0) return "";
        int pos = 0, cnt[26]{};
        char s_buf[n];
        string result;

        for (int i = 0; i < n; ++i) {
            s_buf[i] = s[i] - 'a';
            cnt[s_buf[i]]++;
        }
        while (pos != n) {
            if (cnt[s_buf[pos]] == 0) {
                ++pos;
                continue;
            }
            for (int i = pos; i < n; ++i) {
                if (cnt[s_buf[i]] == 0) continue;
                if (s_buf[i] < s_buf[pos]) pos = i;
                if (--cnt[s_buf[i]] == 0) {
                    cnt[s_buf[i--]] = 1;
                    for (; i > pos; --i) {
                        if (cnt[s_buf[i]]) ++cnt[s_buf[i]];
                    }
                    cnt[s_buf[pos]] = 0;
                    break;
                }
            }
            result.push_back(s_buf[pos++] + 'a');
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    
    string str = "cbacdcbc";
    while (cin>>str)
        cout<<s.removeDuplicateLetters(str)<<endl;
    return 0;
}
