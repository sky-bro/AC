#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<string>> result;
    void _partition(int l, int r, const string &s, vector<vector<bool>> &sub_palindromes, vector<string> &path) {
        if (r < l) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i <= r - l; ++i) {
            if (!sub_palindromes[l][l+i]) continue;
            path.push_back(s.substr(l, i+1));
            _partition(l+i+1, r, s, sub_palindromes, path);
            path.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        result.clear();
        if (n == 0) return result;
        vector<vector<bool>> sub_palindromes(n, vector<bool>(n, true));
        for (int i = 0; i < n - 1; ++i) {
            sub_palindromes[i][i+1] = s[i] == s[i+1];
        }
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                sub_palindromes[i][i + len - 1] = sub_palindromes[i+1][i+len-2] && s[i] == s[i+len-1];
            }
        }
        
        vector<string> path;
        _partition(0, n-1, s, sub_palindromes, path);
        return result;
    }
};