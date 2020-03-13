#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
 private:
  int target_side, n;
  bool dfs(vector<int>& nums, int idx, vector<int>& sides) {
    // have successfully added all matchsticks
    if (idx == n) return true;
    // try adding matchstick nums[idx] to one side
    for (int i = 0; i < 4; ++i) {
      // nums[idx] is too large
      if (sides[i] + nums[idx] > target_side) continue;
      // if some sides[0...i-1] equal to sides[i]
      // only try adding nums[idx] to the first side (of length sides[i])
      int j = i - 1;
      while (j >= 0 && sides[i] != sides[j]) --j;
      if (j != -1) continue;

      // dfs
      sides[i] += nums[idx];
      if (dfs(nums, idx + 1, sides)) return true;  // walk to next idx
      sides[i] -= nums[idx];
    }
    return false;
  }

 public:
  bool makesquare(vector<int>& nums) {
    n = nums.size();
    if (n < 4) return false;  // less than 4 sticks, cannot construct 4 sides
    target_side = accumulate(nums.begin(), nums.end(), 0);
    if (target_side & 3) return false;  // sum of nums is not multiple of 4
    target_side >>= 2;
    vector<int> sides(4);
    sort(nums.rbegin(), nums.rend());  // try bigger num first->faster to fail
    return dfs(nums, 0, sides);
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums = {3, 3, 3, 3, 4};
  Solution s;
  cout << s.makesquare(nums) << endl;
  return 0;
}
