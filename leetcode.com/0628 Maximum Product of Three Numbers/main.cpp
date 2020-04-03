#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maximumProduct(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    // 3pos, 1pos2neg
    return max(nums[n] * nums[n - 1] * nums[n - 2], nums[0] * nums[1] * nums[n - 1]);
  }
};