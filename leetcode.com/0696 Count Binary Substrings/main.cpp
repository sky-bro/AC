#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int countBinarySubstrings(string s) {
    int pre_cnt = 0, cur_cnt = 0, n = s.length(), res = 0;
    for (int i = 0; i < n;) {
      char cur = s[i];
      cur_cnt = 0;
      for (; i < n && s[i] == cur; ++cur_cnt, ++i)
        ;
      res += min(cur_cnt, pre_cnt);
      pre_cnt = cur_cnt;
    }
    return res;
  }
};