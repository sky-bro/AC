#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  int minMoves2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int res = 0, n = nums.size();
    for (int i = 0; i < n / 2; ++i) res += nums[n - 1 - i] - nums[i];
    return res;
  }
};