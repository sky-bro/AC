#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findPairs(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int res = 0;
    for (int i = 0; i < n - 1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (nums[j] - nums[i] == k)
          ++res;
        else if (nums[j] - nums[i] > k)
          break;
        while (j + 1 < n && nums[j + 1] == nums[j]) ++j;
      }
      while (i + 1 < n - 1 && nums[i + 1] == nums[i]) ++i;
    }
    return res;
  }
};