#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isMonotonic(vector<int>& A) {
    bool ok = false, positive = false;
    for (int i = A.size() - 1; i > 0; --i) {
      int cur = A[i] - A[i - 1];
      if (cur == 0)
        continue;
      else if (cur > 0) {
        if (ok && !positive) return false;
        positive = true;
        ok = true;
      } else {
        if (ok && positive) return false;
        positive = false;
        ok = true;
      }
    }
    return true;
  }
};
