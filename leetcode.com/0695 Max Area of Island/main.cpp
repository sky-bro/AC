#include <iostream>
#include <vector>

using namespace std;

int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};

class Solution {
 private:
  int m, n;
  void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j,
           int& cur) {
    for (int k = 0; k < 4; ++k) {
      int ni = i + di[k], nj = j + dj[k];
      if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
        if (vis[ni][nj]) continue;
        vis[ni][nj] = true;
        if (grid[ni][nj]) {
          dfs(grid, vis, ni, nj, ++cur);
        }
      }
    }
  }

 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int max_area = 0;
    m = grid.size();
    n = grid[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (vis[i][j]) continue;
        vis[i][j] = true;
        if (grid[i][j]) {
          int cur = 1;
          dfs(grid, vis, i, j, cur);
          max_area = max(cur, max_area);
        }
      }
    }
    return max_area;
  }
};