#include <cmath>
#include <iostream>

using namespace std;

// ref:
// https://leetcode.com/problems/sum-of-square-numbers/discuss/104935/Fermat
// wiki: Fermat's theorem on sums of two squares
// https://en.wikipedia.org/wiki/Fermat's_theorem_on_sums_of_two_squares

class Solution {
 public:
  bool judgeSquareSum(int c) {
    for (int i = 0; i * i <= c / 2; ++i) {
      int aa = i * i, bb = c - aa, b = sqrt(bb);
      if (bb == b * b) return true;
    }
    return false;
  }
};