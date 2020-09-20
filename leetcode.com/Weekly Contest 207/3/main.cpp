#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

template <typename T>
void printArr(const vector<T>& arr) {
  for (const T& t : arr) cout << t << "\t\t";
  cout << endl;
}

class Solution {
 public:
  int maxProductPath(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    // dp[0]: mins
    // dp[1]: max's
    vector<vector<long long>> dp(2, vector<long long>(n));
    dp[0][0] = dp[1][0] = grid[0][0];
    for (int i = 1; i < n; ++i) dp[0][i] = dp[1][i] = dp[0][i - 1] * grid[0][i];
    for (int i = 1; i < m; ++i) {
      long long l = dp[0][0], r = dp[1][0];
      if (grid[i][0] < 0) {
        dp[0][0] = grid[i][0] * r;
        dp[1][0] = grid[i][0] * l;
      } else {
        dp[0][0] = grid[i][0] * l;
        dp[1][0] = grid[i][0] * r;
      }
      for (int j = 1; j < n; ++j) {
        l = dp[0][j], r = dp[1][j];
        if (grid[i][j] < 0) {
          dp[0][j] = min(1LL * grid[i][j] * r, grid[i][j] * dp[1][j - 1]);
          dp[1][j] = max(1LL * grid[i][j] * l, grid[i][j] * dp[0][j - 1]);
        } else {
          dp[0][j] = min(1LL * grid[i][j] * l, grid[i][j] * dp[0][j - 1]);
          dp[1][j] = max(1LL * grid[i][j] * r, grid[i][j] * dp[1][j - 1]);
        }
      }
      if (i == m - 2) {
        printArr(dp[0]);
        printArr(dp[1]);
        cout << endl;
      }
    }
    printArr(dp[0]);
    printArr(dp[1]);
    cout << endl;
    if (dp[1][n - 1] < 0) return -1;
    return dp[1][n - 1] % MOD;
  }
};

int main(int argc, char const* argv[]) {
  vector<vector<int>> grid = {{-3, 4, 4, 0, 0, 1, 1, 0, 1, 1, -4, -4},
                              {-2, 1, 3, -3, -3, -3, -2, -2, 3, 2, 3, -2},
                              {-4, 2, 2, -3, 3, -1, -1, -4, 2, -2, 0, -2},
                              {0, -1, 3, -2, -4, -1, 3, 4, 1, 4, 3, 1},
                              {2, -2, -3, 1, 3, 4, -4, 0, 3, 2, 0, 4},
                              {3, 2, -2, 4, 1, -3, 1, 1, 0, -3, 0, 4},
                              {-1, -1, -1, -4, 1, 2, 0, -3, -4, 4, -3, 3},
                              {-1, 0, 2, 0, -4, 1, -2, -3, -2, -3, 3, -1},
                              {-2, 4, 4, 2, 2, -4, -4, -3, 2, -3, 3, 0},
                              {2, -2, 3, 4, 4, -2, -2, -3, 0, -3, 4, -1},
                              {1, 4, 2, -3, -4, 3, -1, 1, -4, -1, 1, 3}};
  Solution s;
  cout << s.maxProductPath(grid) << endl;
  return 0;
}
