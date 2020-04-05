#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> minSubsequence(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int n = nums.size();
    vector<int> res;
    int cur_sum = 0;

    for (int i = n - 1; i >= 0 && cur_sum <= sum; --i) {
      cur_sum += nums[i];
      sum -= nums[i];
      res.push_back(nums[i]);
    }
    return res;
  }
};