#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// ref: C++ 16ms O(n) solution (with trivial proof)
// https://leetcode.com/problems/super-washing-machines/discuss/99181/C%2B%2B-16ms-O(n)-solution-(with-trivial-proof)

class Solution {
 public:
  int findMinMoves(vector<int>& machines) {
    int len = machines.size();
    vector<int> sum(len + 1, 0);
    for (int i = 0; i < len; ++i) sum[i + 1] = sum[i] + machines[i];

    if (sum[len] % len) return -1;

    int avg = sum[len] / len;
    int res = 0;
    for (int i = 0; i < len; ++i) {
      int l = i * avg - sum[i];
      int r = (len - i - 1) * avg - (sum[len] - sum[i] - machines[i]);

      if (l > 0 && r > 0)
        res = std::max(res, std::abs(l) + std::abs(r));
      else
        res = std::max(res, std::max(std::abs(l), std::abs(r)));
    }
    return res;
  }
};