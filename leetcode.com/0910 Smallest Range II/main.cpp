#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int smallestRangeII(vector<int>& A, int K) {
    sort(A.begin(), A.end());
    int n = A.size();
    int res = A[n - 1] - A[0];
    // m+-k M+-k
    // abs(m-M) abs(m-M+2k)
    // [1, 10] 5
    // [6, 5] -> 1
    // [1, 10] 8
    // [9, 2] -> 7
    // [1, 2, 9, 10] 8
    // [9, 10, 1, 2] -> 9
    // [9, 10, 17, 18] -> 9
    // [1, 10] 9
    // [10, 1] -> 9
    // [1, 10] 10
    // [11, 0] -> 11
    // [11, 20] -> 9
    int mn = A[0] + K, mx = A[n - 1] - K;
    if (mn > mx) swap(mn, mx);
    for (int i = 1; i < n; ++i) {  // first -K
      int mn_ = A[i] - K;
      int mx_ = A[i - 1] + K;
      if (mn_ > mx_) swap(mn_, mx_);
      res = min(res, max(mx_, mx) - min(mn_, mn));
    }
    return res;
  }
};
