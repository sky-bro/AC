#include <bitset>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum & 1) return false;
    vector<int> dp(sum / 2 + 1);
    dp[0] = 1;
    for (int num : nums) {
      for (int i = sum / 2; i >= num; --i) {
        dp[i] |= dp[i - num];
        // dp[i] += dp[i - num]; // overflow, if number of ways is too big
      }
    }
    return dp[sum / 2];
  }
};
