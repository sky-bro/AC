#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    inline int c_dis(char c1, char c2) {
        // 'A' -- 0, 'Z' -- 25
        return abs((c1 / 6) - (c2 / 6)) + abs((c1 % 6) - (c2 % 6));
    }
    int _minimumDistance(const string &word, int idx, int i, vector<vector<int>> &dp) {
        if (idx == 0) {
            return 0;
        }
        if (dp[idx][i] != -1) return dp[idx][i];
        if (word[idx-1] == i + 'A') return dp[idx][i] = _minimumDistance(word, idx-1, word[idx] - 'A', dp);
        else if (word[idx-1] == word[idx]) return dp[idx][i] = _minimumDistance(word, idx-1, i, dp);
        else return dp[idx][i] = min(c_dis(word[idx-1] - 'A', i) + _minimumDistance(word, idx-1, word[idx] - 'A', dp), c_dis(word[idx-1] - 'A', word[idx] - 'A') + _minimumDistance(word, idx-1, i, dp));
    }
public:
    int minimumDistance(string word) {
        int result = INT32_MAX, tmp, n = word.length();
        if (n <= 2) return 0;
        vector<vector<int>> dp(n, vector<int>(26, -1));
        for (int i = 0; i < 26; ++i) {
            if (i == word[n-1]-'A') continue;
            tmp = _minimumDistance(word, n-1, i, dp);
            if (tmp < result) result = tmp;
        }
        return result;
    }
};