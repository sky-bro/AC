#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// ref: O(n log k) C++ using multiset and updating middle-iterator
// https://leetcode.com/problems/sliding-window-median/discuss/96340/O(n-log-k)-C%2B%2B-using-multiset-and-updating-middle-iterator
class Solution {
 public:
  vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    multiset<int> window(nums.begin(), nums.begin() + k);
    auto mid = next(window.begin(), k / 2);
    vector<double> medians;
    medians.push_back((double(*mid) + *prev(mid, 1 - k % 2)) / 2);
    for (int i = k; i < nums.size(); ++i) {
      window.insert(nums[i]);
      if (nums[i] < *mid) --mid;
      if (nums[i - k] <= *mid) ++mid;
      window.erase(window.lower_bound(nums[i - k]));
      medians.push_back((double(*mid) + *prev(mid, 1 - k % 2)) / 2);
    }
    return medians;
  }
};