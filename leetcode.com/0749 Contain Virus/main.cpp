// ref: [C++] 4ms DFS beats 100%
// https://leetcode.com/problems/contain-virus/discuss/405427/C%2B%2B-4ms-DFS-beats-100
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int containVirus(vector<vector<int>>& grid) {
    while (build_wall(grid))
      ;
    return res;
  }

 private:
  int res = 0;
  int dfs(vector<vector<int>>& grid, int i, int j, int k, int& wall,
          vector<vector<int>>& infected_grid) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
        grid[i][j] < 0)
      return 0;
    if (grid[i][j] == k) { // ?
      if (infected_grid[i][j] > 0) wall++;  // only build wall on boundary
      return 0;
    }

    if (grid[i][j] == 1) {
      grid[i][j] = k;  // grid[i][j] = 1 -> k, not boundary, don't build wall
      return dfs(grid, i + 1, j, k, wall, infected_grid) +
             dfs(grid, i, j + 1, k, wall, infected_grid) +
             dfs(grid, i - 1, j, k, wall, infected_grid) +
             dfs(grid, i, j - 1, k, wall, infected_grid);
    }

    // this square is about to be infected: add 1 to infected_grid[i][j]
    // meaning grid[i][j] will be infected by infected_grid[i][j] islands
    grid[i][j] = k;         // grid[i][j] = 0 -> k
    infected_grid[i][j]++;  // record the boundary
    wall++;                 // only build wall on boundary
    return 1;
  }

  bool build_wall(vector<vector<int>>& grid) {
    // islands marked by k, starts from 2, 1 is the newly infected area
    int k = 1, m = grid.size(), n = grid[0].size(), max_infected = -1, K = 0,
        add_wall = 0;
    vector<vector<int>> infected_grid(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          int wall = 0, infected = dfs(grid, i, j, ++k, wall, infected_grid);
          if (max_infected < infected) {
            max_infected = infected;
            add_wall = wall;
            K = k;
          }
        }
      }
    }

    if (k == 1) return false;  // no free infected area exists, stop

    res += add_wall;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] > 0)
          grid[i][j] =
              (grid[i][j] == K && infected_grid[i][j] <= 1)
                  ? infected_grid[i][j] - 1 // if infected_grid[i][j] == 1, this square is set back to 0 (uninfected)
                  : 1;  // set area inside new wall as -1, else where as 1
      }
    }
    return true;
  }
};
