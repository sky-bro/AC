#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int triangleNumber(vector<int>& nums) {
    int n = nums.size(), res = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; ++i) {
      if (nums[i] == 0) continue;
      for (int j = i + 1; j < n - 1; ++j) {
        int r =
            lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]) -
            nums.begin();
        res += r - j - 1;
      }
    }
    return res;
  }
};