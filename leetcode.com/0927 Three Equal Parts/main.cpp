#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
   * ---[-]====[+]+++
   *     i      j
   * @returns {i, j}
   */
  vector<int> threeEqualParts(vector<int>& A) {
    int ones = 0, n = A.size();
    for (int a : A) ones += a;
    if (ones % 3) return {-1, -1};
    if (ones == 0) return {0, 2};
    int i = 0, j = n - 1;
    // --1[-]-==1[=]=+++++
    //     i      j
    for (int cnt = 0; cnt != ones / 3; ++i) cnt += A[i];
    for (int cnt = 0; cnt != ones / 3 + 1; --j) cnt += A[j];
    j += 2;
    // now A[i-1] = 1, A[j-1] = 1
    // num = A[j:]
    // count trailing zeros
    int zeros = 0;
    while (A[n - 1 - zeros] == 0) ++zeros;
    // adjust i
    for (int z = 0; z < zeros; ++i) {
        if (A[i] == 0) ++z;
        else return {-1, -1};
    }
    // adjust j
    for (int z = 0; z < zeros; ++j) {
        if (A[j] == 0) ++z;
        else return {-1, -1};
    }
    // check
    for (int i1 = n-1, i2 = j-1, i3 = i-1; i1 >= j && i2 >= i && i3 >= 0; --i1, --i2, --i3) {
        if (A[i1] != A[i2] || A[i2] != A[i3]) return {-1, -1};
    }
    return {i-1, j};
  }
};
