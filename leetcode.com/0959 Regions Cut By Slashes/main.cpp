#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 private:
  int cnt, n;
  vector<int> ids;
  void U(int p, int q) {
    int pid = F(p), qid = F(q);
    if (pid != qid) {
      ids[pid] = qid;
      --cnt;
    }
  }
  int F(int x) { return x == ids[x] ? x : ids[x] = F(ids[x]); }

 public:
  int regionsBySlashes(vector<string>& grid) {
    // every cell, 4 parts
    //   0
    // 3 X 1
    //   2
    n = grid.size();
    cnt = n * n * 4;
    ids.resize(n * n * 4);
    iota(ids.begin(), ids.end(), 0);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int base = 4 * (i * n + j);
        if (grid[i][j] == '/') {
          U(base + 0, base + 3);
          U(base + 1, base + 2);
        } else if (grid[i][j] == '\\') {
          U(base + 0, base + 1);
          U(base + 2, base + 3);
        } else {
          U(base + 0, base + 3);
          U(base + 1, base + 2);
          U(base + 0, base + 1);
        }
        // down
        if (i + 1 < n) {
          int tbase = 4 * ((i + 1) * n + j);
          U(tbase + 0, base + 2);
        }
        // right
        if (j + 1 < n) {
          int tbase = 4 * (i * n + j + 1);
          U(tbase + 3, base + 1);
        }
      }
    }
    return cnt;
  }
};
