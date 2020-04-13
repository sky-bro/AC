#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool hasAlternatingBits(int n) {
    bool one = n & 1;
    for (; n; one = !one, n >>= 1) {
      if ((n & 1) != one) {
        return false;
      }
    }
    return true;
  }
};