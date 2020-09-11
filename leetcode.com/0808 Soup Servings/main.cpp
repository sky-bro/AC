#include <iostream>
#include <vector>

using namespace std;

// 4 0
// 3 1
// 2 2
// 1 3

class Solution {
 private:
  double f(int aN, int bN, vector<vector<double>>& dp) {
    if (dp[aN][bN] >= 0) return dp[aN][bN];
    if (aN <= 0) {
      if (bN <= 0) return 0.5;
      return 1;
    } else if (bN <= 0) {
      return 0;
    } else {
      return dp[aN][bN] =
                 0.25 * (f(aN - 4, bN, dp) + f(aN - 3, bN - 1, dp) +
                         f(aN - 2, bN - 2, dp) + f(aN - 1, bN - 3, dp));
    }
  }

 public:
  double soupServings(int N) {
    N = (N + 24) / 25;
    if (N > 200) return 1;
    vector<vector<double>> dp(N + 1, vector<double>(N + 1, -1));
    return f(N, N, dp);
  }
};
