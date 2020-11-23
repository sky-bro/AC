// ref:
// https://leetcode.com/problems/maximize-grid-happiness/discuss/936081/C%2B%2B-5D-DP

#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
int dp[25][7][7][64][64] = {};
class Solution {
 public:
  int nCost(int m, int n, int i, int j, int mask_in, int mask_ex, int d) {
    int diff = 0, up = (1 << (n - 1));
    if (j > 0 && (mask_in & 1)) diff += d - 30;
    if (i > 0 && (mask_in & up)) diff += d - 30;
    if (j > 0 && (mask_ex & 1)) diff += d + 20;
    if (i > 0 && (mask_ex & up)) diff += d + 20;
    return diff;
  }
  int dfs(int m, int n, int p, int in, int ex, int mask_in, int mask_ex) {
    int i = p / n, j = p % n;
    if (i >= m) return 0;
    if (dp[p][in][ex][mask_in][mask_ex])
      return dp[p][in][ex][mask_in][mask_ex] - 1;
    int n_mask_in = (mask_in << 1) & 63, n_mask_ex = (mask_ex << 1) & 63;
    int res = dfs(m, n, p + 1, in, ex, n_mask_in, n_mask_ex);  // space
    if (in > 0) {                                              // intro
      int diff = 120 + nCost(m, n, i, j, mask_in, mask_ex, -30);
      res = max(res,
                diff + dfs(m, n, p + 1, in - 1, ex, n_mask_in + 1, n_mask_ex));
    }
    if (ex > 0) {  // extro
      int diff = 40 + nCost(m, n, i, j, mask_in, mask_ex, 20);
      res = max(res,
                diff + dfs(m, n, p + 1, in, ex - 1, n_mask_in, n_mask_ex + 1));
    }
    dp[p][in][ex][mask_in][mask_ex] = res + 1;
    return res;
  }
  int getMaxGridHappiness(int m, int n, int introvertsCount,
                          int extrovertsCount) {
    return dfs(m, n, 0, introvertsCount, extrovertsCount, 0, 0);
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  int m = 3, n = 1, i = 2, e = 1;
  m = 3, n = 4, i = 6, e = 5;
  cout << s.getMaxGridHappiness(m, n, i, e) << endl;
  return 0;
}
