#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// greedy
class Solution {
 public:
  int bagOfTokensScore(vector<int>& tokens, int P) {
    sort(tokens.begin(), tokens.end());
    int cur = 0, res = 0;
    int i = 0, j = tokens.size();
    while (i < j) {
      if (P >= tokens[i]) {
        res = max(res, ++cur);
        P -= tokens[i];
        ++i;
      } else if (cur) {
        --cur;
        P += tokens[--j];
      } else
        return res;
    }
    return res;
  }
};
