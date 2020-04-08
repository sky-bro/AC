#include <iostream>
#include <vector>

using namespace std;

// key is know how to prune
// no, 1000*1000 dp, no need to prune?
class Solution {
 private:
  int dfs(int n, int cur_n, int clip_len, vector<vector<int>>& dp) {
    if (n == cur_n) return 0;
    if (~dp[clip_len][cur_n]) return dp[clip_len][cur_n];
    int res = -2;
    if (cur_n * 2 <= n) {
      // copy + paste
      res = dfs(n, cur_n * 2, cur_n, dp);
      if (res != -2) res += 2;
    }
    if (cur_n + clip_len <= n) {
      // paste
      int tmp = dfs(n, cur_n + clip_len, clip_len, dp);
      if (tmp != -2) {
        if (res == -2 || tmp + 1 < res) res = tmp + 1;
      }
    }
    return dp[clip_len][cur_n] = res;
  }

 public:
  int minSteps(int n) {
    if (n == 1) return 0;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // already copied + pasted once
    return 2 + dfs(n, 2, 1, dp);
  }
};