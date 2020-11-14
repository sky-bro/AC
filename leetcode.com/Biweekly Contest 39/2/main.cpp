#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumDeletions(string s) {
    int a = 0, b = 0;
    for (char c : s) {
      if (c == 'a') {
        ++a;
      } else
        ++b;
    }
    int res = min(a, b);
    int cnta = a, cntb = 0;
    for (char c : s) {
      if (c == 'a') {
        --cnta;
      } else {
        ++cntb;
      }
      res = min(cnta + cntb, res);
    }
    return res;
  }
};
