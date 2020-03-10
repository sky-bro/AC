#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), res = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0) continue;
        if (j == 0 || grid[i][j - 1] == 0) ++res;      // left
        if (j == n - 1 || grid[i][j + 1] == 0) ++res;  // right
        if (i == 0 || grid[i - 1][j] == 0) ++res;      // up
        if (i == m - 1 || grid[i + 1][j] == 0) ++res;  // down
      }
    }
    return res;
  }
};