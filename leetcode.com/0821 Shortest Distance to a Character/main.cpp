#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> shortestToChar(string S, char C) {
    vector<int> indexes;
    int nS = S.size();
    indexes.push_back(-nS);
    for (int i = 0; i < nS; ++i)
      if (S[i] == C) indexes.push_back(i);
    indexes.push_back(INT32_MAX);
    int i = 1;
    vector<int> res;
    for (int j = 0; j < nS; ++j) {
      while (indexes[i] <= j) ++i;
      res.push_back(min(j - indexes[i - 1], indexes[i] - j));
    }
    return res;
  }
};
