#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int gcd(int x, int y) {
    while (y) {
      swap(x, y);
      y %= x;
    }
    return x;
  }

 public:
  bool canMeasureWater(int x, int y, int z) {
    if (x + y < z) return false;
    if (y > x) swap(x, y);
    if (y == 0) {
      if (x == 0) return z == 0;
      return z % x == 0;
    }
    return z % gcd(x, y) == 0;
  }
};