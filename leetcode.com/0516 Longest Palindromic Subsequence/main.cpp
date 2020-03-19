#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n));
    dp[n - 1][n - 1] = 1;
    for (int i = 0; i < n - 1; ++i) {
      dp[i][i] = 1;
      dp[i][i + 1] = 1 + (s[i] == s[i + 1]);
    }
    for (int d = 2; d < n; ++d) {
      for (int i = 0; i + d < n; ++i) {
        if (s[i] == s[i + d])
          dp[i][i + d] = dp[i + 1][i + d - 1] + 2;
        else
          dp[i][i + d] = max(dp[i][i + d - 1], dp[i + 1][i + d]);
      }
    }
    return dp[0][n - 1];
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string str;
  while (cin >> str) {
    cout << s.longestPalindromeSubseq(str) << endl;
  }
  return 0;
}
