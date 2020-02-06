#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// ref: https://leetcode.com/problems/remove-invalid-parentheses/discuss/75075/Simple-DFS-yet-quite-efficient-in-cpp
class Solution {
private:
    unordered_set<string> result;
    int n;
    void dfs(const string& s, int idx, string path, int extra_left, int extra_right, int open_cnt) {
        if (idx == n) {
            if (open_cnt == 0) result.insert(path);
            return;
        }

        if (s[idx] == '(') {
            if (extra_left) dfs(s, idx+1, path, extra_left-1, extra_right, open_cnt);
            dfs(s, idx+1, path+'(', extra_left, extra_right, open_cnt+1);
        } else if (s[idx] == ')') {
            if (extra_right) dfs(s, idx+1, path, extra_left, extra_right-1, open_cnt);
            if (open_cnt) dfs(s, idx+1, path+')', extra_left, extra_right, open_cnt-1);
        } else {
            dfs(s, idx+1, path + s[idx], extra_left, extra_right, open_cnt);
        }

    }
public:
    vector<string> removeInvalidParentheses(string s) {
        n = s.length();
        int extra_left = 0, extra_right = 0;
        for (char c: s) {
            if (c == '(') {
                ++extra_left;
            } else if (c == ')') {
                extra_left ? --extra_left : ++extra_right;
            }
        }
        dfs(s, 0, "", extra_left, extra_right, 0);
        return vector<string>(result.begin(), result.end());
    }
};