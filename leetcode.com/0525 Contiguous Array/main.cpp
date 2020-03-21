#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> dp;
    dp[0] = -1;
    int cur = 0, res = 0;
    for (int i = 0; i < n; ++i) {
      cur += nums[i] ? 1 : -1;
      auto it = dp.find(cur);
      if (it == dp.end())
        dp.emplace(cur, i);
      else if (i - it->second > res)
        res = i - it->second;
    }
    return res;
  }
};