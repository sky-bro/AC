#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// ref: Java top-down and bottom-up DP solutions
// https://leetcode.com/problems/remove-boxes/discuss/101310/Java-top-down-and-bottom-up-DP-solutions
class Solution {
 private:
  int n;
  int dfs(vector<int>& boxes, int i, int j, int k,
          vector<vector<vector<int>>>& dp) {
    if (i > j) return 0;
    if (dp[i][j][k]) return dp[i][j][k];

    for (; i + 1 <= j && boxes[i + 1] == boxes[i]; ++i, ++k)
      ;
    int res = (k + 1) * (k + 1) + dfs(boxes, i + 1, j, 0, dp);
    for (int m = i + 1; m <= j; ++m) {
      if (boxes[m] == boxes[i]) {
        res = max(
            res, dfs(boxes, i + 1, m - 1, 0, dp) + dfs(boxes, m, j, k + 1, dp));
        while (m <= j && boxes[m] == boxes[i]) ++m;
      }
    }
    return dp[i][j][k] = res;
  }

 public:
  int removeBoxes(vector<int>& boxes) {
    n = boxes.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n)));

    return dfs(boxes, 0, n - 1, 0, dp);
  }
};