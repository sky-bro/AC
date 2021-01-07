#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  int partitionDisjoint(vector<int>& A) {
    int i = 1, mx = A[0], n = A.size(), res = 0, pre_mx = A[0]; // pre_mx is the max element of left part
    for (; i < n; ++i) {
      mx = max(mx, A[i]);
      if (A[i] < pre_mx) {
        res = i;
        pre_mx = mx;
      }
    }
    return res + 1;
  }
};
