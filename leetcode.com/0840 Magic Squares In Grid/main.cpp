#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numMagicSquaresInside(vector<vector<int>>& grid) {
    // init
    int m = grid.size(), n = grid[0].size();
    if (m < 3 || n < 3) return 0;

    // move 3x3 square
    int res = 0;
    for (int i = 0; i + 2 < m; ++i) {    // down
      for (int j = 0; j + 2 < n; ++j) {  // right
        vector<int> num_cnts(10);
        // three row sums, three column sums, two diagonals \ /
        vector<int> sums(8);
        bool ok = true;
        for (int k = 0; k < 9; ++k) {
          int r = k / 3, c = k % 3, num = grid[r + i][c + j];
          if (num < 1 || num > 9 || ++num_cnts[num] > 1) {
            ok = false;
            break;
          }
          sums[r] += num;
          sums[c + 3] += num;
          if (k == 4) {
            sums[6] += num;
            sums[7] += num;
          }
          if (k == 0 || k == 8)
            sums[6] += num;
          else if (k == 2 || k == 6)
            sums[7] += num;
        }
        if (!ok) continue;
        for (int i = 1; i < 8; ++i) {
          if (sums[i] != sums[i - 1]) {
            ok = false;
            break;
          }
        }
        if (ok) ++res;
      }
    }
    return res;
  }
};
