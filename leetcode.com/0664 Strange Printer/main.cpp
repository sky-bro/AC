#include <iostream>
#include <vector>

using namespace std;

// ref: Java O(n^3) DP Solution with Explanation and Simple Optimization
// https://leetcode.com/problems/strange-printer/discuss/106810/Java-O(n3)-DP-Solution-with-Explanation-and-Simple-Optimization

class Solution {
 public:
  int strangePrinter(string s) {
    int n = s.length();
    if (n == 0) return 0;
    string S = "";
    for (int i = 0; i < n;) {
      S.push_back(s[i++]);
      while (i < n && s[i] == S.back()) ++i;
    }
    n = S.length();
    vector<vector<int>> dp(n, vector<int>(n, n));
    for (int i = 0; i < n; ++i) dp[i][i] = 1;
    for (int j = 0; j < n; ++j) {
      for (int i = j; i >= 0; --i) {
        for (int k = i; k < j; ++k) {
          if (S[k] == S[j]) {
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] - 1);
          } else {
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
          }
        }
      }
    }
    return dp[0][n - 1];
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string str;
  while (cin >> str) {
    cout << s.strangePrinter(str) << endl;
  }
  return 0;
}
