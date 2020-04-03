#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findErrorNums(vector<int>& nums) {
    vector<int> res(2);
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      int idx = abs(nums[i]) - 1;
      if (nums[idx] > 0)
        nums[idx] = -nums[idx];
      else
        res[0] = idx + 1;
    }
    for (int i = 0; i < n; ++i) {
      if (nums[i] > 0) {
        res[1] = i + 1;
        break;
      }
    }
    return res;
  }
};