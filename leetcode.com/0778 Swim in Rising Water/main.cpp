#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};

class Solution {
 private:
  int N;
  int res;
  void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<int>> &grid,
           int cur) {
    if (r == N - 1 && c == N - 1) {
      res = cur;
      return;
    }

    for (int i = 0; i < 4; ++i) {
      int nr = r + di[i];
      int nc = c + dj[i];
      if (nr < N && nr >= 0 && nc < N && nc >= 0) {
        if (vis[nr][nc] > max(cur, grid[nr][nc]) && grid[nr][nc] < res) {
          vis[nr][nc] = max(cur, grid[nr][nc]);
          dfs(nr, nc, vis, grid, max(cur, grid[nr][nc]));
        }
      }
    }
  }

 public:
  int swimInWater(vector<vector<int>> &grid) {
    N = grid.size();
    res = N * N - 1;
    vector<vector<int>> vis(N, vector<int>(N, N * N));
    dfs(0, 0, vis, grid, grid[0][0]);
    return res;
  }
};
