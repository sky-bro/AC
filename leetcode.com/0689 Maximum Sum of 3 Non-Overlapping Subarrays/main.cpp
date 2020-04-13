#include <iostream>
#include <numeric>
#include <vector>

#include "leetcode.hpp"

using namespace std;

// ref: Python o(n) time, o(1) space. Greedy solution.
// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/discuss/108231/C%2B%2BJava-DP-with-explanation-O(n)

class Solution {
 public:
  // extend to m non-overlapping subarrays
  // k will be between 1 and floor(nums.length / m).
  vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k, int m = 3) {
    int n = nums.size() - k + 1;
    vector<int> sums(n);  // sums of every contiguous k elements
    sums[0] = accumulate(nums.begin(), nums.begin() + k, 0);
    for (int i = 1; i < n; ++i)
      sums[i] = sums[i - 1] - nums[i - 1] + nums[i - 1 + k];

    /*
    sub_res: (save the best indexes, sub_ress.back() is what we eventually want)
    0
    0 k
    0 k 2k
    0 k 2k 3k
    ... (m rows, as initialized below)
    */
    vector<vector<int>> sub_ress;
    sub_ress.push_back({0});

    /*
    sub_sums: sum of sums at the best indexes (in sub_ress) ...
    sums[0]
    sums[0] + sums[k]
    sums[0] + sums[k] + sums[2k]
    ... (m rows, as initialized below)
    */
    vector<int> sub_sums(m);
    sub_sums[0] = sums[0];

    // initialization
    for (int i = 1; i < m; ++i) {
      // current row is built upon previous row
      vector<int> sub_res = sub_ress.back();
      sub_res.push_back(sub_res.back() + k);
      sub_sums[i] = sub_sums[i - 1] + sums[sub_res.back()];
      sub_ress.push_back(sub_res);
    }

    // scan from left to right for best solution
    // right bound is r (total m indexes, r is the last index)
    for (int r = (m - 1) * k + 1; r < n; ++r) {
      // compute left bound from r
      // l, l+k, l+2k, ..., l+(m-1)k=r (total m indexes)
      int l = r - (m - 1) * k;

      // check if first row could be updated
      if (sums[l] > sub_sums[0]) {
        sub_ress[0][0] = l;
        sub_sums[0] = sums[l];
      }
      l += k;
      // update each row (update their sums and indexes)
      for (int i = 1; i < m; ++i, l += k) {
        // current row is built upon previous row
        int cur_sub_sum = sub_sums[i - 1] + sums[l];
        if (cur_sub_sum > sub_sums[i]) {
          sub_sums[i] = cur_sub_sum;
          sub_ress[i] = sub_ress[i - 1];
          sub_ress[i].push_back(l);
        }
      }
    }

    return sub_ress.back();
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums = {1, 2, 1, 2, 6, 7, 5, 1};
  int k = 2;
  printArr(s.maxSumOfThreeSubarrays(nums, k));
  return 0;
}
