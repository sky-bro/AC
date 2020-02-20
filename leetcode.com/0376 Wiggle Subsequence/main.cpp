#include <iostream>
#include <vector>

using namespace std;

// ref:
// https://leetcode.com/problems/wiggle-subsequence/discuss/84887/C%2B%2B-0ms-O(N)-dynamic-programming-solution
// ref:
// https://leetcode.com/problems/wiggle-subsequence/discuss/84921/3-lines-O(n)-Python-with-explanationproof

class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    int size = nums.size();
    if (size == 0) return 0;
    int up = 1, down = 1;

    for (int i = 1; i < size; ++i) {
      if (nums[i] > nums[i - 1]) {
        up = down + 1;
      } else if (nums[i] < nums[i - 1]) {
        down = up + 1;
      }
    }
    return max(up, down);
  }
};