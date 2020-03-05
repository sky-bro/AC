#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int arrangeCoins(int n) {
    if (n == 0) return 0;
    uint32_t N = n, lo = 1, hi = N;
    N *= 2;

    while (lo < hi) {
      uint32_t mid = lo + (hi - lo + 1) / 2, test = N / mid;
      if (test == mid + 1)
        return mid;
      else if (test < mid + 1) {
        hi = mid - 1;
      } else {
        lo = mid;
      }
    }
    return lo;
  }
};