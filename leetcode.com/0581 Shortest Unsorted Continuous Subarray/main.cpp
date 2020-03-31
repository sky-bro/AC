#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size();
    int _mx = nums[0], l = 1, r = -1;
    for (int i = 1; i < n; ++i) {
      if (nums[i] >= _mx) {
        l += (i == l);
        _mx = nums[i];
        continue;
      }
      r = i;                          // expand rignt bound
      if (l > 0) {                    // expand left bound if l > 0
        if (nums[l - 1] > nums[i]) {  // expand left bound
          auto it = upper_bound(nums.begin(), nums.begin() + l, nums[i]);
          l = it - nums.begin();
        }
      }
    }
    return r < l ? 0 : r - l + 1;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
  nums = {2, 3, 4, 5, 6, 6, 4, 8, 10, 9, 15};  // 7
  nums = {1, 2, 3, 4};                         // 0
  Solution s;
  cout << s.findUnsortedSubarray(nums) << endl;
  return 0;
}
