#include <iostream>
#include <vector>

using namespace std;

// ref:
// https://leetcode.com/problems/split-array-with-same-average/discuss/120830/Simple-DP
// O(NS)

class Solution {
 public:
  bool splitArraySameAverage(vector<int>& A) {
    int N = A.size(), S = 0;
    for (int a : A) S += a;
    // Bit n of p[s] tells me whether it’s possible to build a subset of size n
    // with sum s p[0]=1: possible to build a subset of size 0 with sum 0
    // int p[S + 1] = {1};  // variable-sized object may not be initialized
    vector<int> p(S + 1);
    p[0] = 1;
    // TODO: 背包问题？
    for (int a : A)
      for (int s = S - a; s >= 0; s--) p[s + a] |= p[s] << 1;
    for (int n = 1; n < N; n++)
      if (S * n % N == 0 && p[S * n / N] & (1 << n)) return true;
    return false;
  }
};
