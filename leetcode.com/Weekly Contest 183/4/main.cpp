#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int n;
  int dfs(int i, vector<int>& dp, vector<int>& stoneValue) {
    if (i >= n) return 0;
    if (~dp[i]) return dp[i];

    // 1
    int res = stoneValue[i] - dfs(i + 1, dp, stoneValue);
    // 2
    if (i < n - 1) {
      res = max(res,
                stoneValue[i] + stoneValue[i + 1] - dfs(i + 2, dp, stoneValue));
      // 3
      if (i < n - 2) {
        res = max(res, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] -
                           dfs(i + 3, dp, stoneValue));
      }
    }
    return dp[i] = res;
  }

 public:
  string stoneGameIII(vector<int>& stoneValue) {
    n = stoneValue.size();
    vector<int> dp(n, -1);
    int res = dfs(0, dp, stoneValue);
    if (res > 0) {
      return "Alice";
    } else if (res < 0) {
      return "Bob";
    } else {
      return "Tie";
    }
  }
};
