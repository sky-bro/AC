#include <iostream>
#include <vector>

using namespace std;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

class Solution {
 public:
  vector<vector<int>> spiralMatrixIII(int R, int C, int r, int c) {
    int cnt = R * C - 1;
    int len = 0;
    vector<vector<int>> res;
    res.push_back({r, c});
    if (!cnt) return res;
    for (int i = 1;; ++i) {
      len += i & 1;
      for (int j = 0; j < len; ++j) {
        r += dr[i % 4], c += dc[i % 4];
        if (r >= 0 && r < R && c >= 0 && c < C) {
          res.push_back({r, c});
          if (--cnt == 0) return res;
        }
      }
    }
  }
};
