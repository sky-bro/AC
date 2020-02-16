#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

// [[1,2],[1,2],[3,3],[1,5],[1,5]] 5
// [[1,5],[1,5],[1,5],[2,3],[2,3]] 5
class Solution {
 public:
  int maxEvents(vector<vector<int>>& events) {
    multiset<pair<int, int>> st;
    for (auto& vi : events) {
      st.insert(make_pair(vi[0], vi[1]));
    }

    int res = 0;
    while (!st.empty()) {
      ++res;
      auto it = st.begin();
      int last = it->first;
      st.erase(it);
      for (it = st.begin(); it->first == last; it = st.begin()) {
        int second = it->second;
        st.erase(it);
        if (second > last) st.emplace(last + 1, second);
      }
    }
    return res;
  }
};