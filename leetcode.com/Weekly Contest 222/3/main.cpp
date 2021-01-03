#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();

const int MOD = 1e9 + 7;
typedef long long ll;

class Solution {
 public:
  int waysToSplit(vector<int>& nums) {
    int n = nums.size();
    for (int i = 1; i < n; ++i) nums[i] += nums[i - 1];
    ll res = 0;
    for (int i = 0; i < n - 2; ++i) {
      int s1 = nums[i];
      int s2_max = (nums[n - 1] - nums[i]) / 2;
      int s2_min = s1;
      if (s2_max < s2_min) break;
      auto it = lower_bound(nums.begin() + i + 1, nums.begin() + (n - 1), s1 + s2_min);
      auto it2 = upper_bound(nums.begin() + i + 1, nums.begin() + (n - 1), s1 + s2_max);
      res = (res + (it2 - it)) % MOD;
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums = {1, 1, 1};
  cout << s.waysToSplit(nums) << endl;
  nums = {1, 2, 2, 2, 5, 0};
  cout << s.waysToSplit(nums) << endl;
  return 0;
}
