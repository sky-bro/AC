#include <iostream>
#include <vector>

using namespace std;

int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};

class Solution {
 private:
  int R, C, res, cnt;
  void dfs(vector<vector<int>> &grid, int r, int c, vector<vector<bool>> &vis,
           int cur) {
    if (grid[r][c] == 2) {
      if (cnt == cur - 1) ++res;
      return;
    }
    for (int i = 0; i < 4; ++i) {
      int nr = r + di[i];
      int nc = c + dj[i];
      if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] != -1 &&
          !vis[nr][nc]) {
        vis[nr][nc] = true;
        dfs(grid, nr, nc, vis, cur + 1);
        vis[nr][nc] = false;
      }
    }
  }

 public:
  int uniquePathsIII(vector<vector<int>> &grid) {
    R = grid.size(), C = grid[0].size();
    res = cnt = 0;
    vector<vector<bool>> vis(R, vector<bool>(C));
    int r, c;
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        if (grid[i][j] == 1) {
          r = i;
          c = j;
        } else if (grid[i][j] == 0) {
          ++cnt;
        }
      }
    }
  found_start:
    vis[r][c] = true;
    dfs(grid, r, c, vis, 0);
    return res;
  }
};
