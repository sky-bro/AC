#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

const int n = 40000;
int cnts[n + 10];
class Solution {
 public:
  int minIncrementForUnique(vector<int>& A) {
    memset(cnts, 0, sizeof(cnts));
    for (int a : A) ++cnts[a];
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (cnts[i] > 1) {
        cnts[i + 1] += cnts[i] - 1;
        res += cnts[i] - 1;
      }
    }
    return res + cnts[n] * (cnts[n] - 1) / 2;
  }
};
