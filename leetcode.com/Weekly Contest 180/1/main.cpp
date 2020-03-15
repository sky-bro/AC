#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> luckyNumbers(vector<vector<int>>& matrix) {
    vector<int> res;
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; ++i) {
      int min_j = 0, min_num = matrix[i][0];
      for (int j = 1; j < n; ++j) {
        if (matrix[i][j] < min_num) {
          min_j = j;
          min_num = matrix[i][j];
        }
      }
      int ii = 0;
      for (; ii < m && matrix[ii][min_j] <= min_num; ++ii)
        ;
      if (ii == m) res.push_back(min_num);
    }
    return res;
  }
};