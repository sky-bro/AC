#include <iostream>
#include <vector>

using namespace std;

// ref: Java Solution, BFS
// https://leetcode.com/problems/01-matrix/discuss/101021/Java-Solution-BFS
// ref: 18-line C++ DP Solution, O(n), Easy to Understand
// https://leetcode.com/problems/01-matrix/discuss/101023/18-line-C%2B%2B-DP-Solution-O(n)-Easy-to-Understand

class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> res(m, vector<int>(n, m + n));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j]) {
          if (i > 0) res[i][j] = min(res[i - 1][j] + 1, res[i][j]);
          if (j > 0) res[i][j] = min(res[i][j - 1] + 1, res[i][j]);
        } else
          res[i][j] = 0;
      }
    }
    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        if (matrix[i][j]) {
          if (i < m - 1) res[i][j] = min(res[i + 1][j] + 1, res[i][j]);
          if (j < n - 1) res[i][j] = min(res[i][j + 1] + 1, res[i][j]);
        }
      }
    }

    return res;
  }
};