#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minAddToMakeValid(string S) {
    int left_cnt = 0;
    int res = 0;
    for (char c : S) {
      if (c == '(') {
        ++left_cnt;
      } else if (left_cnt) {
        --left_cnt;
      } else
        ++res;
    }
    res += left_cnt;
    return res;
  }
};
