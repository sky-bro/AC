#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    int n = nums[0].size(), m = nums.size() * n;
    if (m != r * c) return nums;
    vector<vector<int>> res(r, vector<int>(c));
    for (int i = 0; i < m; ++i) {
      int r1 = i / n, c1 = i % n, r2 = i / c, c2 = i % c;
      res[r2][c2] = nums[r1][c1];
    }
    return res;
  }
};