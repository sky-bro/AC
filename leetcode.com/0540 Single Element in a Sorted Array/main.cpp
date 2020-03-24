#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int m = (l + r) / 2;
      bool odd = (m - l) & 1;
      if (nums[m] == nums[m + 1]) {
        if (odd)
          r = m - 1;
        else
          l = m + 2;
      } else {
        if (odd)
          l = m + 1;
        else if (nums[m] != nums[m - 1])
          return nums[m];
        else
          r = m - 2;
      }
    }
    return nums[l];
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
  cout << s.singleNonDuplicate(nums) << endl;
  return 0;
}
