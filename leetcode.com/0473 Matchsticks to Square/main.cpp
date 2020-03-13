#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int target_side;
  int n;
  bool dfs(vector<int>& nums, int idx, vector<int>& sides) {
    if (idx == n) return true;
    if (nums[idx] + sides[0] <= target_side) {
      sides[0] += nums[idx];
      if (dfs(nums, idx + 1, sides)) return true;
      sides[0] -= nums[idx];
    }
    if (sides[1] != sides[0] && nums[idx] + sides[1] <= target_side) {
      sides[1] += nums[idx];
      if (dfs(nums, idx + 1, sides)) return true;
      sides[1] -= nums[idx];
    }
    if (sides[2] != sides[1] && sides[2] != sides[0] &&
        nums[idx] + sides[2] <= target_side) {
      sides[2] += nums[idx];
      if (dfs(nums, idx + 1, sides)) return true;
      sides[2] -= nums[idx];
    }
    if (sides[3] != sides[2] && sides[3] != sides[1] && sides[3] != sides[0] &&
        nums[idx] + sides[3] <= target_side) {
      sides[3] += nums[idx];
      if (dfs(nums, idx + 1, sides)) return true;
      sides[3] -= nums[idx];
    }
    return false;
  }

 public:
  bool makesquare(vector<int>& nums) {
    target_side = 0;
    n = nums.size();
    if (n < 4) return false;
    for (int num : nums) target_side += num;
    if (target_side & 3) return false;
    target_side >>= 2;
    vector<int> sides(4);
    return dfs(nums, 0, sides);
  }
};