#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findLengthOfLCIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    int res = 1;
    for (int i = 1, len = 1; i < n; len = 1, ++i) {
      while (i < n && nums[i] > nums[i - 1]) {
        ++i;
        ++len;
      }
      res = max(res, len);
    }
    return res;
  }
};