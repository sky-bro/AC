#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> ori_skyline(m + n);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ori_skyline[j] = max(ori_skyline[j], grid[i][j]);
        ori_skyline[i + n] = max(ori_skyline[i + n], grid[i][j]);
      }
    }
    int res = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        res += min(ori_skyline[j], ori_skyline[i + n]) - grid[i][j];
      }
    }
    return res;
  }
};
