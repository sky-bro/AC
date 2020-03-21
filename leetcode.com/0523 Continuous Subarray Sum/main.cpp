#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    if (n < 2) return false;
    if (k == 0) {
      for (int i = 1; i < n; ++i) {
        if (nums[i] != 0) ++i;
        if (nums[i - 1] == 0) return true;
      }
      return false;
    } else if (k < 0)
      k = -k;  // not necessary
    unordered_map<int, unordered_set<int>> dp;
    dp[nums[0] %= k].insert(0);
    dp[0].insert(-1);
    for (int i = 1; i < n; ++i) {
      dp[nums[i] = (nums[i - 1] + nums[i]) % k].insert(i);
      if (dp[nums[i]].size() - (nums[i - 1] == nums[i]) > 1) return true;
    }
    return false;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums = {23, 2, 4, 6, 7};
  int k = -6;
  Solution s;
  cout << s.checkSubarraySum(nums, k) << endl;
  return 0;
}
