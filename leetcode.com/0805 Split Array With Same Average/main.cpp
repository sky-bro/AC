#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// TLE
// ref:
// https://leetcode.com/problems/split-array-with-same-average/discuss/120667/C%2B%2B-Solution-with-explanation-early-termination-(Updated-for-new-test-case)

class Solution {
 private:
  int n;
  bool chk(vector<int>& A, int i, int k, int target) {
    if (k == 0) return target == 0;
    if (i >= n) return false;
    if (A[i] * k < target) return false;
    for (; i <= n - k; ++i) {
      if (A[i] <= target && chk(A, i + 1, k - 1, target - A[i])) return true;
    }
    return false;
  }

 public:
  bool splitArraySameAverage(vector<int>& A) {
    n = A.size();
    int total_sum = accumulate(A.begin(), A.end(), 0);
    sort(A.rbegin(), A.rend());
    for (int k = 1; k < n; ++k) {
      if (total_sum * k % n == 0 && chk(A, 0, k, total_sum * k / n))
        return true;
    }
    return false;
  }
};
