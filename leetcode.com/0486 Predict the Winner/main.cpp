#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int dfs(int l, int r, vector<int>& nums, vector<vector<int>>& dp,
          vector<vector<bool>>& visited) {
    if (l == r) return nums[l];
    if (visited[l][r]) return dp[l][r];
    visited[l][r] = true;
    return dp[l][r] = max(nums[l] - dfs(l + 1, r, nums, dp, visited),
                          nums[r] - dfs(l, r - 1, nums, dp, visited));
  }

 public:
  bool PredictTheWinner(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n));
    vector<vector<bool>> visited(n, vector<bool>(n));
    return dfs(0, n - 1, nums, dp, visited) >= 0;
  }
};