#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> numberOfLines(vector<int>& widths, string S) {
    int lines = 0, len = 100;
    for (char c : S) {
      len += widths[c - 'a'];
      if (len > 100) {
        ++lines;
        len = widths[c - 'a'];
      }
    }
    return {lines, len};
  }
};
