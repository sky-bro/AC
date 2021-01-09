#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> sortArrayByParityII(vector<int>& A) {
    for (int i = A.size() - 2, j = i + 1; i >= 0; i -= 2, j -= 2) {
      while (i >= 0 && (A[i] & 1) == 0) i -= 2;
      while (j >= 0 && (A[j] & 1)) j -= 2;
      if (i >= 0)
        swap(A[i], A[j]);
      else
        break;
    }
    return A;
  }
};
