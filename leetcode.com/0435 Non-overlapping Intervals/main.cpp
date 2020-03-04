#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(
        intervals.begin(), intervals.end(),
        [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });

    int res = intervals.size(), n = res;
    for (int i = 0; i < n;) {
      --res;
      int ii = i;
      for (; i < n && intervals[i][0] < intervals[ii][1]; ++i)
        ;
    }
    return res;
  }
};