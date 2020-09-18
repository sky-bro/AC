#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
      int j = 0, k = n - 1;
      for (; j < k; ++j, --k) {
        swap(A[i][j], A[i][k]);
        A[i][j] ^= 1;
        A[i][k] ^= 1;
      }
      if (j == k) A[i][j] ^= 1;
    }
    return A;
  }
};
