#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int hammingDistance(int x, int y) { return __builtin_popcount(x ^ y); }
};