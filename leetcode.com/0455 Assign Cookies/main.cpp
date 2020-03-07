#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int res = 0, gn = g.size(), sn = s.size();
    for (int i = 0, j = 0; i < gn && j < sn; ++i) {
      while (j < sn && s[j] < g[i]) ++j;
      if (j++ < sn) ++res;
    }
    return res;
  }
};