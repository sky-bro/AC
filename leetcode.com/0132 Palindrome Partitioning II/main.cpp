#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int min_cut;
    void _minCut(int l, int r, const string &s, vector<vector<bool>> &sub_palindromes, int cur_cut) {
        if (r < l) {
            if (cur_cut <= min_cut) min_cut = cur_cut - 1;
            return;
        }
        for (int i = 0; i <= r - l; ++i) {
            if (!sub_palindromes[l][l+i]) continue;
            _minCut(l+i+1, r, s, sub_palindromes, cur_cut + 1);
        }
    }
public:
    
    int minCut(string s) {
        int n = s.length();
        if (n == 0) return 0;
        min_cut = n;
        vector<vector<bool>> sub_palindromes(n, vector<bool>(n, true));
        for (int i = 0; i < n - 1; ++i) {
            sub_palindromes[i][i+1] = s[i] == s[i+1];
        }
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                sub_palindromes[i][i + len - 1] = sub_palindromes[i+1][i+len-2] && s[i] == s[i+len-1];
            }
        }
        
        _minCut(0, n-1, s, sub_palindromes, 0);
        return min_cut;
    }
};