#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int countSegments(string s) {
    int res = 0;
    int i = 0, n = s.length();
    while (i < n) {
      for (; i < n && isspace(s[i]); ++i)
        ;
      if (i < n) ++res;
      for (; i < n && !isspace(s[i]); ++i)
        ;
    }
    return res;
  }
};
