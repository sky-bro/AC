#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int oddEvenJumps(vector<int>& A) {
    int n = A.size(), res = 1;
    vector<vector<int>> dp(n, vector<int>(2, 0));
    // dp[x][0]: even, dp[x][1]: odd
    dp[n - 1][0] = dp[n - 1][1] = 1;
    map<int, int> mp;
    mp[A[n - 1]] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
      // dp[i][1], jump up, >= A[i]
      auto it = mp.lower_bound(A[i]);
      if (it != mp.end()) {
        dp[i][1] = dp[it->second][0];
      }
      // dp[i][0], jump down, <= A[i]
      it = mp.upper_bound(A[i]);
      if (it != mp.begin()) {
        dp[i][0] = dp[prev(it)->second][1];
      }
      mp[A[i]] = i;
      res += dp[i][1];  // odd jump, 1st
    }
    return res;
  }
};
