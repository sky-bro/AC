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
  vector<int> findBall(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> res(n, -1);
    for (int i = 0; i < n; ++i) {
      int ii = i;
      bool ok = true;
      for (int j = 0; j < m; ++j) {
        if (grid[j][ii] == 1) {
          ++ii;
          if (ii == n || grid[j][ii] == -1) {
            ok = false;
            break;
          }
        } else {
          --ii;
          if (ii < 0 || grid[j][ii] == 1) {
            ok = false;
            break;
          }
        }
      }
      if (ok) res[i] = ii;
    }
    return res;
  }
};
