#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestCommonSubsequence(string s1, string s2) {
    int n1 = s1.length(), n2 = s2.length();
    if (n1 > n2) {
      swap(n1, n2);
      swap(s1, s2);
    }
    vector<int> dp(n2 + 1);
    for (int i = 1; i <= n1; ++i) {
      int pre = 0;
      for (int j = 1; j <= n2; ++j) {
        int bak = dp[j];
        dp[j] = s1[i - 1] == s2[j - 1] ? pre + 1 : max(dp[j - 1], bak);
        pre = bak;
      }
    }
    return dp[n2];
  }
};