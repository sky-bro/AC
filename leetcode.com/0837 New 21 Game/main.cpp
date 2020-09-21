#include <iostream>
#include <vector>

using namespace std;

// ref:
// https://leetcode.com/problems/new-21-game/discuss/132334/One-Pass-DP-O(N)

class Solution {
 public:
  double new21Game(int N, int K, int W) {
    if (N < K)
      return 0;
    else if (K == 0 || N >= K + W)
      return 1;
    double WSum = 1.0, res = 0;
    vector<double> dp(N + 1);
    dp[0] = 1;
    for (int i = 1; i <= N; ++i) {
      dp[i] = WSum / W;
      if (i < K)
        WSum += dp[i];
      else
        res += dp[i];
      if (i >= W) WSum -= dp[i - W];
    }
    return res;
  }
};
