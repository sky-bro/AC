#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int binaryGap(int n) {
    int res = 0;
    int cur = 0;
    while ((n & 1) == 0) n >>= 1;
    n >>= 1;
    while (n) {
      ++cur;
      if (n & 1) {
        res = max(res, cur);
        cur = 0;
      }
      n >>= 1;
    }
    return res;
  }
};
