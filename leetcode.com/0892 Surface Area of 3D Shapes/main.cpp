#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int surfaceArea(vector<vector<int>>& grid) {
    int n = grid.size();
    int res = 4 * grid[0][0] + (grid[0][0] ? 2 : 0);
    for (int i = 1; i < n; ++i) {
      res += 4 * grid[0][i] + (grid[0][i] ? 2 : 0) -
             2 * min(grid[0][i - 1], grid[0][i]);
    }
    for (int i = 1; i < n; ++i) {
      res += 4 * grid[i][0] + (grid[i][0] ? 2 : 0) -
             2 * min(grid[i][0], grid[i - 1][0]);
      for (int j = 1; j < n; ++j) {
        res += 4 * grid[i][j] + (grid[i][j] ? 2 : 0) -
               2 * min(grid[i][j], grid[i - 1][j]) -
               2 * min(grid[i][j], grid[i][j - 1]);
      }
    }
    return res;
  }
};
