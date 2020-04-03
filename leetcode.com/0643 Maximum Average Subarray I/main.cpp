#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  double findMaxAverage(vector<int>& nums, int k) {
    int sum = accumulate(nums.begin(), nums.begin() + k, 0), max_sum = sum;
    int n = nums.size();
    for (int i = k; i < n; ++i) {
      sum = sum - nums[i - k] + nums[i];
      if (sum > max_sum) max_sum = sum;
    }
    return double(max_sum) / k;
  }
};