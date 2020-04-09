#include <iostream>
#include <vector>

using namespace std;

int di[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dj[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

class Solution {
 public:
  vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
    int m = M.size(), n = M[0].size();
    vector<vector<int>> res(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int sum = 0, cnt = 0;
        for (int k = 0; k < 9; ++k) {
          int ni = i + di[k];
          int nj = j + dj[k];
          if (ni >= 0 && nj >= 0 && ni < m && nj < n) {
            sum += M[ni][nj];
            ++cnt;
          }
        }
        res[i][j] = sum/cnt;
      }
    }
    return res;
  }
};