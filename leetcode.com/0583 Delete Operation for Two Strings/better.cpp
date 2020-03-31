#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  string s1, s2;
  int n1, n2;
  int LCS() {
    vector<int> dp(n2 + 1);
    for (int i = 1; i <= n1; ++i) {
      int pre = 0;
      for (int j = 1; j <= n2; ++j) {
        int bak = dp[j];
        if (s1[i - 1] == s2[j - 1]) {
          dp[j] = pre + 1;
        } else {
          dp[j] = max(dp[j - 1], dp[j]);
        }
        pre = bak;
      }
    }
    return dp[n2];
  }

 public:
  int minDistance(string word1, string word2) {
    s1 = word1;
    s2 = word2;
    n1 = s1.length();
    n2 = s2.length();
    if (n2 < n1) {
      swap(n1, n2);
      swap(s1, s2);
    }
    int lcs = LCS();
    return n1 - lcs + n2 - lcs;
  }
};