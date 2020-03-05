#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res;

    for (int i = nums.size() - 1; i >= 0; --i) {
      int idx = abs(nums[i]) - 1;
      nums[idx] *= -1;
      if (nums[idx] > 0) res.push_back(idx + 1);
    }

    return res;
  }
};