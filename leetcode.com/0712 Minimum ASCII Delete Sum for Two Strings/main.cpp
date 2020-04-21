#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 private:
  int n1, n2;
  string s1, s2;
  int dfs(int i, int j, vector<vector<int>>& dp) {
    if (i == n1 || j == n2) return 0;
    if (~dp[i][j]) return dp[i][j];
    int res;
    if (s1[i] == s2[j]) {
      res = 2 * s1[i];
      res += dfs(i + 1, j + 1, dp);
    } else {
      res = max(dfs(i + 1, j, dp), dfs(i, j + 1, dp));
    }
    return dp[i][j] = res;
  }

 public:
  int minimumDeleteSum(string s1, string s2) {
    int res = 0;
    n1 = s1.length();
    n2 = s2.length();
    this->s1 = s1;
    this->s2 = s2;
    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    return accumulate(s1.begin(), s1.end(), 0) +
           accumulate(s2.begin(), s2.end(), 0) - dfs(0, 0, dp);
  }
};
