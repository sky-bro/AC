#include <iostream>
#include <vector>

using namespace std;

// dp
// minimax?
class Solution {
 public:
  int getMoneyAmount(int n) {
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 1; i < n; ++i) {        // range width
      for (int j = 0; j + i < n; ++j) {  // range start
        // int l = j, r = j + i;
        dp[i][j] = min(j + 1 + dp[i - 1][j + 1], j + i + 1 + dp[i - 1][j]);
        for (int k = 0; k < i - 1; ++k) {  // first sub range width: r-l
          dp[i][j] = min(dp[i][j],
                         j + k + 2 + max(dp[k][j], dp[i - k - 2][j + k + 2]));
        }
      }
    }
    return dp[n - 1][0];
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int n;
  while (cin >> n) {
    cout << s.getMoneyAmount(n) << endl;
  }
  return 0;
}
