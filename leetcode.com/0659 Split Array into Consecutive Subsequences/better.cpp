#include <iostream>
#include <queue>
#include <vector>

#include "leetcode.hpp"

using namespace std;

// ref: Java O(n) time & O(1) space solution -- greedily extending shorter subsequence
// https://leetcode.com/problems/split-array-into-consecutive-subsequences/discuss/106495/Java-O(n)-time-and-O(1)-space-solution-greedily-extending-shorter-subsequence

class Solution {
 public:
  bool isPossible(vector<int>& nums) {
    int pre = 123, p1 = 0, p2 = 0, p3 = 0;  // pre's start value doesn't matter
    int cur = 0, cnt = 0, c1 = 0, c2 = 0, c3 = 0;
    for (int i = nums.size() - 1; i >= 0;
         pre = cur, p1 = c1, p2 = c2, p3 = c3) {
      for (cur = nums[i], cnt = 0; i >= 0 && cur == nums[i]; --i, ++cnt)
        ;
      if (cur != pre - 1) {
        // new start
        if (p1 || p2) return false;
        c1 = cnt;
        c2 = c3 = 0;
      } else {
        // continue from pre
        if (cnt < p1 + p2) return false;
        // p1, p2 must be appended to, then
        // greedy: always try to add to p3, instead of start a new sequence
        c1 = max(0, cnt - (p1 + p2 + p3));
        c2 = p1;
        c3 = cnt - c1 - c2;
      }
    }
    return p1 == 0 && p2 == 0;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  string line;
  while (getline(cin, line)) {
    vector<int> nums = stringToIntegerVector(line);

    bool ret = Solution().isPossible(nums);

    string out = boolToString(ret);
    cout << out << endl;
  }
  return 0;
}
