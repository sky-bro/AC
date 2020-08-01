#include <iostream>

using namespace std;

// ref: Simple Java one pass O(n) solution with explaination
// https://leetcode.com/problems/swap-adjacent-in-lr-string/discuss/113789/Simple-Java-one-pass-O(n)-solution-with-explaination

class Solution {
 public:
  bool canTransform(string s1, string s2) {
    for (int i1 = s1.length(), i2 = s2.length(); i1 >= 0 && i2 >= 0; --i1, --i2) {
      while (i1 >= 0 && s1[i1] == 'X') --i1;
      while (i2 >= 0 && s2[i2] == 'X') --i2;
      if (i1 < 0 && i2 < 0) return true;
      if (i1 < 0 || i2 < 0) return false;
      if (s1[i1] != s2[i2]) return false;
      if (s1[i1] == 'R' && i1 > i2) return false;
      if (s1[i1] == 'L' && i1 < i2) return false;
    }
    return true;
  }
};
