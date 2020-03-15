#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int res = 0, n = nums.size();
    for (int i = 0; i < n;) {
      while (i < n && nums[i] == 0) ++i;
      int cur = 0;
      while (i < n && nums[i] == 1) {
        ++cur;
        ++i;
      }
      res = max(res, cur);
    }
    return res;
  }
};