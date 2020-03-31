#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  string s1, s2;
  int n1, n2;
  int LCS() {
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
    for (int i = 1; i <= n1; ++i) {
      for (int j = 1; j <= n2; ++j) {
        if (s1[i - 1] == s2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[n1][n2];
  }

 public:
  int minDistance(string word1, string word2) {
    s1 = word1;
    s2 = word2;
    n1 = s1.length();
    n2 = s2.length();
    int lcs = LCS();
    return n1 - lcs + n2 - lcs;
  }
};