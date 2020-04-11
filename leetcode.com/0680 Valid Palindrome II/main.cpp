#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool validPalindrome(string s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
      if (s[l] == s[r]) {
        ++l;
        --r;
        continue;
      }
      // delete left one
      int l1 = l + 1, r1 = r;
      while (l1 < r1) {
        if (s[l1] != s[r1]) break;
        ++l1;
        --r1;
        continue;
      }
      if (l1 >= r1) return true;
      // delete right one
      int l2 = l, r2 = r-1;
      while (l2 < r2) {
        if (s[l2] != s[r2]) return false;
        ++l2;
        --r2;
        continue;
      }
      return true;
    }
    return true;
  }
};