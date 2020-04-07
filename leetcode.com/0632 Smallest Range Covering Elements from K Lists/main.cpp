#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// ref: Clean C++ priority_queue solution using iterators
// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/discuss/104886/Clean-C%2B%2B-priority_queue-solution-using-iterators
class Solution {
 public:
  vector<int> smallestRange(vector<vector<int>>& nums) {
    typedef vector<int>::iterator vi;

    struct comp {
      bool operator()(pair<vi, vi> p1, pair<vi, vi> p2) {
        return *p1.first > *p2.first;
      }
    };

    int lo = INT32_MAX, hi = INT32_MIN;
    priority_queue<pair<vi, vi>, vector<pair<vi, vi>>, comp> pq;
    for (auto& row : nums) {
      lo = min(lo, row[0]);
      hi = max(hi, row[0]);
      pq.push({row.begin(), row.end()});
    }

    vector<int> ans = {lo, hi};
    while (true) {
      auto p = pq.top();
      pq.pop();
      ++p.first;
      if (p.first == p.second) break;
      pq.push(p);

      lo = *pq.top().first;
      hi = max(hi, *p.first);
      if (hi - lo < ans[1] - ans[0]) ans = {lo, hi};
    }
    return ans;
  }
};