#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// dp
class Solution {
 public:
  int minDeletionSize(vector<string>& A) {
    int m = A.size(), n = A[0].size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (dp[j] < dp[i]) continue;
        int k = 0;
        for (; k < m; ++k) {
          if (A[k][j] > A[k][i]) break;
        }
        if (k == m) dp[i] = dp[j] + 1;
      }
    }
    return n - *max_element(dp.begin(), dp.end());
  }
};
