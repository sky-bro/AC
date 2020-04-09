#include <iostream>

using namespace std;

// read (& compare) from right to left
// O(1) extra space
// ref: [C++/Java/Python] O(N) time and O(1) space
// https://leetcode.com/problems/backspace-string-compare/discuss/135603/C%2B%2BJavaPython-O(N)-time-and-O(1)-space
class Solution {
 public:
  bool backspaceCompare(string S, string T) {
    for (int i = S.length() - 1, j = T.length() - 1;; i--, j--) {
      for (int back = 0; i >= 0 && (back || S[i] == '#'); --i)
        back += S[i] == '#' ? 1 : -1;
      for (int back = 0; j >= 0 && (back || T[j] == '#'); --j)
        back += T[j] == '#' ? 1 : -1;
      if (i < 0 || j < 0 || S[i] != T[j]) return i == -1 && j == -1;
    }
  }
};