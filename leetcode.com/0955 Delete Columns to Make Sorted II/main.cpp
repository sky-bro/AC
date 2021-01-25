#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minDeletionSize(vector<string>& A) {
    int res = 0;
    int m = A.size(), n = A[0].size();
    vector<string> B(m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        B[j].push_back(A[j][i]);
      }
      if (!is_sorted(B.begin(), B.end())) {
        ++res;
        for (int j = 0; j < m; ++j) {
          B[j].pop_back();
        }
      }
    }
    return res;
  }
};
