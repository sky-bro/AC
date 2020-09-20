#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numSpecial(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    int cnt = 0;
    auto chk = [&](int i, int j) {
      if (mat[i][j] == 0) return false;
      for (int ii = 0; ii < m; ++ii) {
        if (ii == i) continue;
        if (mat[ii][j]) return false;
      }
      for (int jj = 0; jj < n; ++jj) {
        if (jj == j) continue;
        if (mat[i][jj]) return false;
      }
      return true;
    };
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        cnt += chk(i, j);
      }
    }
    return cnt;
  }
};
