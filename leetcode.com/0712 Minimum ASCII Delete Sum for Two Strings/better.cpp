#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// try use iterate solution, O(n) space

class Solution {
 public:
  int minimumDeleteSum(string s1, string s2) {
    int n1 = s1.length(), n2 = s2.length();
    vector<int> dp(n2 + 1);
    for (int i = 1; i <= n2; ++i) dp[i] = s2[i-1] + dp[i - 1];
    int a, a_bak;  // up left
    for (int i = 1; i <= n1; ++i) {
      a = dp[0];
      dp[0] += s1[i-1];
      for (int j = 1; j <= n2; ++j) {
        a_bak = dp[j];
        dp[j] = (s1[i-1] == s2[j-1]) ? a : min(dp[j - 1] + s2[j-1], dp[j] + s1[i-1]);
        a = a_bak;
      }
    }
    return dp[n2];
  }
};

class Solution0 {
 public:
  int minimumDeleteSum(string s1, string s2) {
    int res = 0;
    int n1 = s1.length(), n2 = s2.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
    for (int i = 0; i < n2; ++i) {
      dp[0][i + 1] = s2[i] + dp[0][i];
    }
    for (int i = 1; i <= n1; ++i) {
      dp[i][0] = s1[i - 1] + dp[i - 1][0];
      for (int j = 1; j <= n2; ++j) {
        if (s1[i - 1] == s2[j - 1])
          dp[i][j] = dp[i - 1][j - 1];
        else {
          dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
        }
      }
    }
    return dp[n1][n2];
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string s1, s2;
  while (cin >> s1 >> s2) {
    cout << s.minimumDeleteSum(s1, s2) << '\n';
  }
  return 0;
}
