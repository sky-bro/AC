#include <iostream>
#include <vector>

using namespace std;

// ref:
// https://leetcode.com/problems/circular-array-loop/discuss/94148/Java-SlowFast-Pointer-Solution
class Solution {
 public:
  bool circularArrayLoop(vector<int>& nums) {
    int n = nums.size();
#define Next(i) ((i + n + nums[i] % n) % n)
    for (int i = 0; i < n; ++i) {
      if (nums[i] == 0) continue;  // visited
      bool right = nums[i] > 0;
      int slow = i, fast = Next(i);
      while (nums[i] * nums[fast] > 0 && nums[i] * nums[Next(fast)] > 0) {
        if (slow == fast) {
          if (slow == Next(slow)) {
            break;
          }
          return true;
        }
        slow = Next(slow);
        fast = Next(Next(fast));
      }
      for (int j = i; nums[j] * nums[i] > 0;) {
        int tmp = Next(j);
        nums[j] = 0;
        j = tmp;
      }
    }
    return false;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums = {2, 2, 2, 2, 2, 4, 7};
  //   nums = {-2, 1, -1, -2, -2};
  nums = {2, -1, 1, 2, 2};
  cout << s.circularArrayLoop(nums) << endl;
  return 0;
}
