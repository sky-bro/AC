#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                     int k) {
    vector<vector<int>> res;
    int n1 = nums1.size(), n2 = nums2.size();
    if (n1 == 0 || n2 == 0 || k <= 0) return res;
    auto cmp = [&nums1, &nums2](pair<int, int>& a, pair<int, int>& b) {
      return nums1[a.first] + nums2[a.second] >
             nums1[b.first] + nums2[b.second];
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>
        min_heap(cmp);
    min_heap.emplace(0, 0);
    while (k-- > 0 && min_heap.size()) {
      auto idx_pair = min_heap.top();
      min_heap.pop();
      res.push_back({nums1[idx_pair.first], nums2[idx_pair.second]});
      if (idx_pair.first + 1 < nums1.size())
        min_heap.emplace(idx_pair.first + 1, idx_pair.second);
      if (idx_pair.first == 0 && idx_pair.second + 1 < nums2.size())
        min_heap.emplace(idx_pair.first, idx_pair.second + 1);
    }
    return res;
  }
};
