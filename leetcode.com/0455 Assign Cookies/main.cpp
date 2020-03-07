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
    for (int j = 0; res < gn && j < sn; ++j) {
      if (g[res] <= s[j]) ++res;
    }
    return res;
  }
};