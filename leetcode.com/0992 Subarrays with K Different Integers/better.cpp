#include <bits/stdc++.h>
using namespace std;
int __fastio = []() {
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  cin.tie(nullptr);
  return 0;
}();

class Solution {
 public:
  int atMost(vector<int>& nums, int k) {
    if (k == 0) return 0;
    int l = 0, r = 0, res = 0, n = nums.size();
    vector<int> cnt(n + 1);
    while (r < n) {
      if (++cnt[nums[r++]] == 1) --k;
      while (k < 0) {
        if (--cnt[nums[l++]] == 0) ++k;
      }
      // number of subarray:
      //  with at most k distinct numbers
      //  and ends at index r
      res += r - l + 1;
    }
    return res;
  }

  int subarraysWithKDistinct(vector<int>& nums, int k) {
    return atMost(nums, k) - atMost(nums, k - 1);
  }
};

int main() {
  Solution s;
  vector<int> nums = {27, 27, 43, 28, 11, 20, 1,  4,  49, 18, 37, 31, 31, 7,
                      3,  31, 50, 6,  50, 46, 4,  13, 31, 49, 15, 52, 25, 31,
                      35, 4,  11, 50, 40, 1,  49, 14, 46, 16, 11, 16, 39, 26,
                      13, 4,  37, 39, 46, 27, 49, 39, 49, 50, 37, 9,  30, 45,
                      51, 47, 18, 49, 24, 24, 46, 47, 18, 46, 52, 47, 50, 4,
                      39, 22, 50, 40, 3,  52, 24, 50, 38, 30, 14, 12, 1,  5,
                      52, 44, 3,  49, 45, 37, 40, 35, 50, 50, 23, 32, 1,  2};
  int k = 20;
  cout << s.subarraysWithKDistinct(nums, k) << endl;  // 149
}
