#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    int m = rowSum.size(), n = colSum.size();
    vector<vector<int>> res(m, vector<int>(n));
    for (int i = 0, j = 0; i < m && j < n;) {
      int x = min(rowSum[i], colSum[j]);
      res[i][j] = x;
      rowSum[i] -= x;
      colSum[j] -= x;
      if (rowSum[i] == 0) ++i;
      if (colSum[j] == 0) ++j;
    }
    return res;
  }
};
