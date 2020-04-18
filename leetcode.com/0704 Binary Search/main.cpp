#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (nums[m] == target) return m;
      nums[m] < target ? l = m + 1 : r = m - 1;
    }
    return -1;
  }
};