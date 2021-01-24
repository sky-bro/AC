#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minDeletionSize(vector<string>& A) {
    int n = A[0].size(), res = 0;
    for (int i = 0; i < n; ++i) {
      char pre = 0;
      for (const string& a : A) {
        if (a[i] < pre) {
          ++res;
          break;
        }
        pre = a[i];
      }
    }
    return res;
  }
};
