#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  // find min subarray (exclude A): res = sum(A) - mn;
  // or find non-empty max-subarray: res = mx
  int maxSubarraySumCircular(vector<int>& A) {
    int n = A.size();
    partial_sum(A.begin(), A.end(), A.begin());
    int res = A[0];
    int mn = min(0, A[0]), mx = A[0], total = A.back();
    for (int i = 1; i < n; ++i) {  // ends with i
      res = max(res, max(A[i] - mn, total - (A[i] - mx)));
      mn = min(mn, A[i]);
      mx = max(mx, A[i]);
    }
    return res;
  }
};
