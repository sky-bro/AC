#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline bool is_low(char c) { return c & 0b100000; }
class Solution {
 public:
  bool detectCapitalUse(string word) {
    int i = 1, n = word.length();
    if (n == 1) return true;
    if (is_low(word[0])) {
      return all_of(word.begin() + 1, word.end(), is_low);
    } else if (is_low(word[1])) {
      return all_of(word.begin() + 2, word.end(), is_low);
    } else {
      return all_of(word.begin() + 2, word.end(),
                    [](char c) { return !is_low(c); });
    }
    return i == n;
  }
};