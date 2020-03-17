#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 private:
  int n;
  int dfs(vector<int> nums, int S, int idx,
          vector<unordered_map<int, int>>& dp) {
    if (idx == n) return S == 0;
    if (nums[idx] < S) return 0;
    auto it = dp[idx].find(S);
    if (it != dp[idx].end()) return it->second;
    return dp[idx][S] =
               dfs(nums, S - (nums[idx] - nums[idx + 1]), idx + 1, dp) +
               dfs(nums, S + (nums[idx] - nums[idx + 1]), idx + 1, dp);
  }

 public:
  int findTargetSumWays(vector<int>& nums, int S) {
    n = nums.size();
    nums.push_back(0);
    for (int i = n - 2; i >= 0; --i) nums[i] += nums[i + 1];
    vector<unordered_map<int, int>> dp(n);
    return dfs(nums, S, 0, dp);
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int S = 0;
  cout << s.findTargetSumWays(nums, S) << endl;
  return 0;
}
