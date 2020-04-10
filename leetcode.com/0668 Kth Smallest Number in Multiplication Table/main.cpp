#include <iostream>
#include <vector>

using namespace std;

// similar problem: 378. Kth Smallest Element in a Sorted Matrix
// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m *n;
        while (l < r) {
          int mid = (l + r) / 2;
          int /*j = n,*/ cnt = 0;
          for (int i = 1; i <= m; ++i) {
            // while (i*j > mid) --j;
            // cnt += j;
            cnt += (mid / i < n) ? mid / i : n;
          }
          if (cnt < k) l = mid + 1;
          else r = mid;
        }
        return l;
    }
};