#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxWidthOfVerticalArea(vector<vector<int>>& points) {
    set<int> st;
    for (auto& p : points) {
      st.insert(p[0]);
    }
    if (st.size() == 0) return 0;
    int mx = 1;
    for (auto it = st.begin(); next(it) != st.end(); ++it) {
      auto it2 = next(it);
      mx = max(mx, (*it2) - (*it));
    }
    return mx;
  }
};
