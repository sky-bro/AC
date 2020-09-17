#include <iostream>
#include <vector>

using namespace std;

int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};

class Solution {
 private:
  int n;
  vector<vector<int>> grid;
  vector<vector<bool>> vis;
  vector<int> id2size;
  int dfs(int i, int j, int id) {
    int sz = 1;
    grid[i][j] = id;
    vis[i][j] = true;
    for (int k = 0; k < 4; ++k) {
      int ni = di[k] + i, nj = dj[k] + j;
      if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
        if (grid[ni][nj] == 0 || vis[ni][nj]) continue;
        sz += dfs(ni, nj, id);
      }
    }
    return sz;
  }

 public:
  int largestIsland(vector<vector<int>>& g) {
    grid = g;
    n = grid.size();
    vis = vector<vector<bool>>(n, vector<bool>(n));
    int id = 1;
    id2size.clear();
    id2size.push_back(0);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (vis[i][j] || grid[i][j] == 0) continue;
        id2size.push_back(dfs(i, j, id++));
      }
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j]) continue;
        int sz = 1;  // flip 0
        vector<int> ids;
        for (int k = 0; k < 4; ++k) {
          int ni = di[k] + i, nj = dj[k] + j;
          if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
            bool ok = true;
            for (int id : ids) {
              if (id == grid[ni][nj]) {
                ok = false;
                break;
              }
            }
            if (ok) {
              ids.push_back(grid[ni][nj]);
              sz += id2size[grid[ni][nj]];
            }
          }
        }
        res = max(res, sz);
      }
    }
    return res == 0 ? n * n : res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<int>> grid = {{1, 1}, {1, 0}};
  grid = {{1, 0}, {0, 1}};
  cout << s.largestIsland(grid) << endl;
  return 0;
}
