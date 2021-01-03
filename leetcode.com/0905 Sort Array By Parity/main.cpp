#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> sortArrayByParity(vector<int>& A) {
    for (int i = 0, j = A.size() - 1; i < j; ++i, --j) {
      while (i <= j && (A[i] & 1) == 0) ++i;
      while (i <= j && A[j] & 1) --j;
      if (i < j) swap(A[i], A[j]);
    }
    return A;
  }
};
