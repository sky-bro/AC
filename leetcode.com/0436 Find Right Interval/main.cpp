#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findRightInterval(vector<vector<int>>& intervals) {
    map<int, int> start2index;
    int n = intervals.size();
    for (int i = 0; i < n; ++i) {
      start2index[intervals[i][0]] = i;
    }
    vector<int> res;
    for (int i = 0; i < n; ++i) {
      auto it = start2index.lower_bound(intervals[i][1]);
      if (it == start2index.end())
        res.push_back(-1);
      else
        res.push_back(it->second);
    }
    return res;
  }
};