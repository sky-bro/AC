#include <iostream>
#include <vector>

using namespace std;

// ref: Reservoir sampling
// https://en.wikipedia.org/wiki/Reservoir_sampling
// 水塘抽样(Reservoir Sampling)问题
// https://www.cnblogs.com/strugglion/p/6424874.html
class Solution {
 private:
  int n;
  vector<int> nums;

 public:
  Solution(vector<int>& nums) {
    n = nums.size();
    this->nums = nums;
  }

  int pick(int target) {
    int cnt = 1;
    int res = -1;
    for (int i = 0; i < n; ++i) {
      if (nums[i] == target) {
        if ((rand() % cnt++) == 0) {
          res = i;
        }
      }
    }
    return res;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */