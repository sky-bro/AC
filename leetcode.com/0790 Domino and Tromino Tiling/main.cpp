#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

class Solution {
 private:
  int f1(vector<vector<int>> &dp, int n) {
    if (n == 1)
      return 1;
    else if (n == 2)
      return 2;
    if (~dp[0][n]) return dp[0][n];
    return dp[0][n] = ((f1(dp, n - 1) + f1(dp, n - 2)) % MOD +
                       2 * f2(dp, n - 1) % MOD) %
                      MOD;
  }
  int f2(vector<vector<int>> &dp, int n) {
    if (n == 1)
      return 0;
    else if (n == 2)
      return 1;
    if (~dp[1][n]) return dp[1][n];
    return dp[1][n] = (f1(dp, n - 2) + f2(dp, n - 1)) % MOD;
  }

 public:
  int numTilings(int N) {
    vector<vector<int>> dp(2, vector<int>(1001, -1));
    return f1(dp, N);
  }
};
