#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// ref: [C++/Java/1-line Python] Sort and One Pass
// https://leetcode.com/problems/sum-of-subsequence-widths/discuss/161267/C%2B%2BJava1-line-Python-Sort-and-One-Pass

class Solution {
 public:
  int sumSubseqWidths(vector<int>& A) {
    sort(A.begin(), A.end());
    long c = 1, res = 0, mod = 1e9 + 7, n = A.size();
    for (int i = 0; i < n; ++i, c = c * 2 % mod)
      res = (res + A[i] * c - A[n - i - 1] * c) % mod;
    return (res + mod) % mod;
  }
};
