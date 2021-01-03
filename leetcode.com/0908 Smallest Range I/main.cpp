#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int smallestRangeI(vector<int>& A, int K) {
    auto p = minmax_element(A.begin(), A.end());
    int d = *p.second - *p.first;
    return d > 2 * K ? d - 2 * K : 0;
  }
};
