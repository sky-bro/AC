#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int consecutiveNumbersSum(int N) {
    // l l+1 l+2 ... l+n-1
    // n(2l+n-1) = 2N
    // l >= 1 // consecutive positive integers
    N <<= 1;
    int res = 0;
    for (int n = 1; n * n < N; ++n) {
      if (N % n) continue;
      int l = N / n - n + 1;
      if (l & 1) continue;
      ++res;
    }
    return res;
  }
};
