#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> decrypt(vector<int>& code, int k) {
    int n = code.size();
    vector<int> res(n);
    if (k == 0) return res;
    for (int i = 0; i < n; ++i) {
      int j = (i + k + n) % n;
      int d = k > 0 ? -1 : 1;
      int sum = 0;
      for (; j != i; j = (j + d + n) % n) {
        sum += code[j];
      }
      res[i] = sum;
    }
    return res;
  }
};
