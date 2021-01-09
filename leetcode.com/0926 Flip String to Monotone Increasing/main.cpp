#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minFlipsMonoIncr(string S) {
    int n = S.size(), cur = 0;
    for (char c : S) cur += (c == '0');
    int res = cur;
    for (char c : S) res = min(res, cur += (c == '0' ? -1 : 1));
    return res;
  }
};
