#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int projectionArea(vector<vector<int>>& grid) {
    int n = grid.size();
    int res = n * n;
    for (int i = 0; i < n; ++i) {
      res += *max_element(grid[i].begin(), grid[i].end());
    }
    for (int i = 0; i < n; ++i) {
      int mx = INT32_MIN;
      for (int j = 0; j < n; ++j) {
        res -= grid[j][i] == 0;
        mx = max(mx, grid[j][i]);
      }
      res += mx;
    }
    return res;
  }
};
