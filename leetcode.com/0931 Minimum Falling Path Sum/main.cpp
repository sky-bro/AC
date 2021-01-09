#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& A) {
    // simple dp problem
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(n + 2, 10100));
    copy(A[n - 1].begin(), A[n - 1].end(), dp[n - 1].begin() + 1);
    // dp[i][j] = min(dp[i+1][j-1], dp[i+1][j], dp[i+1][j+1]);
    for (int i = n - 2; i >= 0; --i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j] = A[i][j - 1] +
                   min(dp[i + 1][j - 1], min(dp[i + 1][j], dp[i + 1][j + 1]));
      }
    }
    return *min_element(dp[0].begin(), dp[0].end());
  }
};
