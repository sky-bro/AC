#include <iostream>
#include <vector>

#include "leetcode.hpp"

using namespace std;

class Solution {
 public:
  int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<pair<int, int>> dp(n, {1, 1});
    for (int i = 1; i < n; ++i) {
      for (int j = i - 1; j >= 0; --j) {
        if (nums[i] > nums[j]) {
          if (dp[i].first < dp[j].first + 1) {
            dp[i].first = dp[j].first+1;
            dp[i].second = dp[j].second;
          } else if (dp[i].first == dp[j].first+1) {
            dp[i].second += dp[j].second;
          }
        }
      }
    }
    int max_len = 0, max_len_cnt = 0;
    for (auto& p : dp) {
      if (p.first == max_len)
        max_len_cnt += p.second;
      else if (p.first > max_len) {
        max_len = p.first;
        max_len_cnt = p.second;
      }
    }
    return max_len_cnt;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  string line;
  while (cin >> line) {
    vector<int> nums = stringToIntegerVector(line);
    cout << s.findNumberOfLIS(nums) << endl;
  }
  return 0;
}
