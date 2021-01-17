#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

class Solution {
 public:
  int largestSubmatrix(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 1; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j]) {
          matrix[i][j] += matrix[i - 1][j];
        }
      }
    }
    int res = 0;
    for (int i = 0; i < m; ++i) {
      sort(matrix[i].rbegin(), matrix[i].rend());
      for (int j = 0; j < n && matrix[i][j]; ++j) {
        res = max(res, matrix[i][j] * (j + 1));
      }
    }
    return res;
  }
};
