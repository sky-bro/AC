#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int countSubstrings(string s) {
    int n = s.length(), res = n;
    vector<vector<bool>> dp(n, vector<bool>(n));
    fill(dp[0].begin(), dp[0].end(), true);
    for (int i = 0; i < n - 1; ++i) {
      if (s[i] == s[i + 1]) {
        dp[1][i] = true;
        ++res;
      }
    }
    for (int i = 2; i < n; ++i) {
      for (int j = 0; i + j < n; ++j) {
        // s[j..j+i]
        if (s[j] == s[j + i] && dp[i - 2][j + 1]) {
          dp[i][j] = true;
          ++res;
        }
      }
    }
    return res;
  }
};