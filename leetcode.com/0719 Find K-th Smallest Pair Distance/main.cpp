#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size(), l = 0, r = nums[n - 1] - nums[0];
    auto chk = [&](int m) {
      int cnt = 0;
      for (int i = 0; i < n - 1; ++i) {
        cnt += upper_bound(nums.begin() + i + 1, nums.end(), nums[i] + m) -
               (nums.begin() + i) - 1;
      }
      return cnt;
    };
    while (l < r) {
      int m = l + (r - l) / 2;
      int cnt = chk(m);
      if (cnt >= k) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return l;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums = {1, 3, 1};
  int k = 1;
  nums = {1, 3, 1, 32, 2, 1, 3, 3, 4, 5, 6, 6, 7, 9, 8, 7};
  k = 10;
  cout << s.smallestDistancePair(nums, k) << endl;
  return 0;
}
