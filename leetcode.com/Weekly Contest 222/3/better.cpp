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
    partial_sum(nums.begin(), nums.end(), nums.begin());
    ll res = 0;
    int j = 1, k = 1;
    for (int i = 0; i < n - 2; j = max(++i + 1, j)) {
      int s1 = nums[i];
      int s2_max = (nums[n - 1] - nums[i]) / 2;
      int s2_min = s1;
      if (s2_max < s2_min) break;
      while (j < n - 1 && nums[j] - nums[i] < s2_min) ++j;
      while (k < n - 1 && nums[k] - nums[i] <= s2_max) ++k;
      res = (res + (k - j)) % MOD;
    }
    return res;
  }
};


int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums = {1, 1, 1};
  nums = {0, 0, 0, 0};  // 3
  cout << s.waysToSplit(nums) << endl;
  nums = {1, 2, 2, 2, 5, 0};
  cout << s.waysToSplit(nums) << endl;
  return 0;
}
