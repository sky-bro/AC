#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  int mirrorReflection(int p, int q) {
    int y0 = lcm(p, q);
    int x_cnt = y0 / q;
    int y_cnt = y0 / p;
    for (int x = x_cnt, y = y_cnt;; x += x_cnt, y += y_cnt) {
      if ((x & 1)) {
        if (y & 1) {
          return 1;
        } else {
          return 0;
        }
      } else {
        if (y & 1) {
          return 2;
        }
      }
    }
  }
};
