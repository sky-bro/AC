#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> readBinaryWatch(int num) {
    vector<string> res;
    char buf[8];
    for (int i = 0; i < 1024; ++i) {
      if (__builtin_popcount(i) != num) continue;
      int h = i >> 6, m = i & 63;
      if (h > 11 || m > 59) continue;
      sprintf(buf, "%d:%02d", h, m);
      res.push_back(buf);
    }
    return res;
  }
};