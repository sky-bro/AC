#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int countVowelStrings(int n) {
    vector<vector<int>> dp(5, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) dp[0][i] = 1;
    for (int i = 0; i < 5; ++i) dp[i][0] = i + 1;
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < 5; ++j) {
        dp[j][i] += dp[j][i - 1] + dp[j - 1][i];
      }
    }
    return dp[4][n - 1];
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int n;
  while (cin >> n) {
    cout << s.countVowelStrings(n) << endl;
  }
  return 0;
}
