#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int countSubstrings(string s, string t) {
    int n1 = s.length(), n2 = t.length();
    int min_len = min(n1, n2);
    int diff = 0, res = 0;
    for (int i = 0; i < n1; ++i) {
      for (int j = 0; j < n2; ++j) {
        if (s[i] != t[j]) {
          ++res;
          diff = 1;
        } else {
          diff = 0;
        }
        for (int len = 1; len + i < n1 && len + j < n2; ++len) {
          if (s[len + i] == t[len + j]) {
            if (diff == 1) {
              ++res;
            }
          } else {
            if (diff == 1) {
              break;
            } else {
              ++res;
              ++diff;
            }
          }
        }
      }
    }
    return res;
  }
};
