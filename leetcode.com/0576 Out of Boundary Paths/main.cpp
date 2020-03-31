#include <iostream>
#include <vector>

using namespace std;

const int di[4] = {0, 0, 1, -1};
const int dj[4] = {1, -1, 0, 0};
const int MOD = 1e9 + 7;

class Solution {
 private:
  int m, n;
  int dfs(int i, int j, int N, vector<vector<vector<int>>> &dp) {
    if (i < 0 || i >= m || j < 0 || j >= n) return 1;
    if (N == 0) return 0;
    if (~dp[i][j][N]) return dp[i][j][N];
    int res = 0;
    for (int k = 0; k < 4; ++k) {
      int ni = i + di[k];
      int nj = j + dj[k];
      res += dfs(ni, nj, N - 1, dp);
      res %= MOD;
    }
    return dp[i][j][N] = res;
  }

 public:
  int findPaths(int m, int n, int N, int i, int j) {
    this->m = m;
    this->n = n;
    vector<vector<vector<int>>> dp(
        m, vector<vector<int>>(n, vector<int>(N + 1, -1)));
    return dfs(i, j, N, dp);
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int m = 2, n = 2, N = 2, i = 0, j = 0;
  cout << s.findPaths(m, n, N, i, j) << endl;
  return 0;
}
