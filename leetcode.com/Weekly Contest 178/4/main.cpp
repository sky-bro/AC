#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// TLE
class Solution0 {
 private:
  int m, n, res = INT32_MAX;
  void dfs(int i, int j, vector<vector<int>>& grid, int cur_cost,
           vector<vector<bool>>& visited) {
    if (cur_cost >= res) return;
    if (i == m - 1 && j == n - 1) {
      res = min(res, cur_cost);
      return;
    }
    visited[i][j] = true;
    if (i > 0 && visited[i - 1][j] == false) {  // up
      visited[i - 1][j] = true;
      dfs(i - 1, j, grid, cur_cost + (grid[i][j] != 4), visited);
      visited[i - 1][j] = false;
    }
    if (i < m - 1 && visited[i + 1][j] == false) {  // down
      visited[i + 1][j] = true;
      dfs(i + 1, j, grid, cur_cost + (grid[i][j] != 3), visited);
      visited[i + 1][j] = false;
    }
    if (j > 0 && visited[i][j - 1] == false) {  // left
      visited[i][j - 1] = true;
      dfs(i, j - 1, grid, cur_cost + (grid[i][j] != 2), visited);
      visited[i][j - 1] = false;
    }
    if (j < n - 1 && visited[i][j + 1] == false) {  // right
      visited[i][j + 1] = true;
      dfs(i, j + 1, grid, cur_cost + (grid[i][j] != 1), visited);
      visited[i][j + 1] = false;
    }
    visited[i][j] = false;
  }

 public:
  int minCost(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    res = INT32_MAX;
    // vector<vector<int>> costs(m, vector<int>(n, INT32_MAX));
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    dfs(0, 0, grid, 0, visited);
    return res;
  }
};

typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x, to) for (x = 0; x < (to); x++)
#define FORR(x, arr) for (auto& x : arr)
#define ITR(x, c) for (__typeof(c.begin()) x = c.begin(); x != c.end(); x++)
#define ALL(a) (a.begin()), (a.end())
#define ZERO(a) memset(a, 0, sizeof(a))
#define MINUS(a) memset(a, 0xff, sizeof(a))
//-------------------------------------------------------

int H, W;
int D[303][303];

class Solution {
 public:
  int minCost(vector<vector<int>>& grid) {
    int H = grid.size();
    int W = grid[0].size();
    int y, x, cy, cx;
    FOR(y, H) FOR(x, W) D[y][x] = 101010;
    D[0][0] = 0;
    priority_queue<pair<int, int>> Q;
    Q.push({0, 0});
    while (Q.size()) {
      int co = -Q.top().first;
      int cy = Q.top().second / 100;
      int cx = Q.top().second % 100;
      Q.pop();

      if (D[cy][cx] != co) continue;
      int dy[4] = {0, 0, 1, -1};
      int dx[4] = {1, -1, 0, 0};
      int i;
      FOR(i, 4) {
        int co2 = co + (grid[cy][cx] != i + 1);
        int ty = cy + dy[i];
        int tx = cx + dx[i];
        if (ty < 0 || ty >= H || tx < 0 || tx >= W) continue;
        if (co2 < D[ty][tx]) {
          D[ty][tx] = co2;
          Q.push({-co2, ty * 100 + tx});
        }
      }
    }
    return D[H - 1][W - 1];
  }
};

int main(int argc, char const* argv[]) {
  vector<vector<int>> grid = {
      {1, 1, 1, 1}, {2, 2, 2, 2}, {1, 1, 1, 1}, {2, 2, 2, 2}};
  Solution s;
  grid = {{1, 1, 3}, {3, 2, 2}, {1, 1, 4}};
  cout << s.minCost(grid) << endl;

  return 0;
}
