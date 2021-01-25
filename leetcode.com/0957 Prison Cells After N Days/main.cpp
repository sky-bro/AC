#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> prisonAfterNDays(vector<int>& cells, int N) {
    int cur = 0;
    vector<int> t(256, -1);
    for (int i = 0; i < 8; ++i) {
      if (cells[i]) cur |= (1 << i);
    }
    t[cur] = 0;

    for (int i = 1; i <= N; ++i) {
      cur = ~((cur << 1) ^ (cur >> 1));
      cur &= ((1 << 7) - 2);
      if (~t[cur]) {
        // loop found
        int idx = t[cur] + (N - i) % (i - t[cur]);  // loop size: i - t[cur]
        cur = 0;
        while (t[cur] != idx) ++cur;
        break;
      }
      t[cur] = i;
    }

    for (int i = 0; i < 8; ++i) {
      cells[i] = bool(cur & (1 << i));
    }
    return cells;
  }
};
