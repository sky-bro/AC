#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
    int res = 0, n = A.size();
    for (int i = 0, j; i < n;) {
      int len = 0;
      j = i;
      while (j < n && A[j] <= R) {
        if (A[j] >= L) {
          ++len;
          res += len;
          ++j;
        } else {
          int sub_len = 0;
          for (; j < n && A[j] < L; ++j) {
            ++len;
            ++sub_len;
            res += len - sub_len;
          }
        }
      }
      i = j + 1;
    }
    return res;
  }
};
