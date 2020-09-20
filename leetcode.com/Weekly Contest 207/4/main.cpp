#include <iostream>
#include <vector>

using namespace std;

// ref:
// https://leetcode.com/problems/minimum-cost-to-connect-two-groups-of-points/discuss/855041/C%2B%2BPython-DP-using-mask

class Solution {
 private:
  int sz1, sz2;
  int dfs(vector<vector<int>> &cost, vector<int> &min_sz2, int i, int mask,
          vector<vector<int>> &dp) {
    if (~dp[i][mask]) return dp[i][mask];
    int res = i == sz1 ? 0 : INT32_MAX;
    if (i == sz1) {
      // connect remaining nodes in group 2
      for (int j = 0; j < sz2; ++j) {
        if ((mask & (1 << j)) == 0) {  // not connected
          res += min_sz2[j];
        }
      }

    } else {
      // connect i-th node of group 1
      for (int j = 0; j < sz2; ++j) {
        res = min(res,
                  cost[i][j] + dfs(cost, min_sz2, i + 1, mask | (1 << j), dp));
      }
    }
    return dp[i][mask] = res;
  }

 public:
  int connectTwoGroups(vector<vector<int>> &cost) {
    sz1 = cost.size();
    sz2 = cost[0].size();
    vector<int> min_sz2(sz2, INT32_MAX);
    vector<vector<int>> dp(sz1 + 1, vector<int>(1 << sz2, -1));
    for (int j = 0; j < sz2; ++j) {
      for (int i = 0; i < sz1; ++i) {
        min_sz2[j] = min(min_sz2[j], cost[i][j]);
      }
    }
    return dfs(cost, min_sz2, 0, 0, dp);
  }
};
