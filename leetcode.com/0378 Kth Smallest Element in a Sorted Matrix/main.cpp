#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// ref:
// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/85182/My-solution-using-Binary-Search-in-C%2B%2B
class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int l = matrix[0][0], r = matrix[n - 1][n - 1], mid;
    while (l < r) {
      mid = l + r >> 1;
      int cnt = 0, j = n - 1;
      // awesome here, in O(n) time (from the first comment)
      for (int i = 0; i < n; i++) {
        while (j >= 0 && matrix[i][j] > mid) j--;
        cnt += j + 1;
      }
      if (cnt < k)
        l = mid + 1;
      else
        r = mid;
    }
    return l;
  }
};