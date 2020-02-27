#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int n, res;
  void calc(int len) {
    if (len < 3) return;
    len -= 2;
    res += len * (len + 1) / 2;
  }

 public:
  int numberOfArithmeticSlices(vector<int>& A) {
    n = A.size();
    res = 0;
    for (int l = 0; l < n - 2;) {
      int r = l + 1;
      for (int d = A[r++] - A[l]; r < n && A[r] - A[r - 1] == d; ++r)
        ;
      calc(r - l);
      l = r - 1;
    }
    return res;
  }
};