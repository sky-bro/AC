#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

// ref:
// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/discuss/83599/Accepted-C%2B%2B-codes-with-explanation-and-references
class Solution {
 private:
  int bestMaxSum(vector<int>& nums, int k) {
    int sum = 0, maxS = INT32_MIN;
    // Kadane's Algorithm
    // it's a trick. Maybe O(n) to solve this problem
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      maxS = max(sum, maxS);
      if (sum == k) {
        return k;
      }
      if (sum < 0) sum = 0;
    }
    if (maxS <= k) {
      return maxS;
    }

    set<int> sums;
    int n = nums.size(), pre_sum = 0, res = INT32_MIN;
    sums.insert(0);
    for (int i = 0; i < n; ++i) {
      pre_sum += nums[i];
      auto it = upper_bound(sums.begin(), sums.end(), pre_sum - k - 1);
      if (it != sums.end()) {
        res = max(res, pre_sum - *it);
        if (res == k) return k;
      }
      sums.insert(pre_sum);
    }
    return res;
  }

 public:
  int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    int m = matrix.size();
    if (m == 0) return 0;
    int n = matrix[0].size();
    if (n == 0) return 0;
    int res = INT32_MIN;
    if (m > n) {
      for (int l = 0; l < n; ++l) {
        vector<int> column(m);
        for (int r = l; r < n; ++r) {
          for (int i = 0; i < m; ++i) {
            column[i] += matrix[i][r];
          }
          res = max(res, bestMaxSum(column, k));
          if (res == k) return k;
        }
      }
    } else {
      for (int l = 0; l < m; ++l) {
        vector<int> row(n);
        for (int r = l; r < m; ++r) {
          for (int i = 0; i < n; ++i) {
            row[i] += matrix[r][i];
          }
          res = max(res, bestMaxSum(row, k));
          if (res == k) return k;
        }
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<int>> matrix = {{1, 0, 1}, {0, -2, 3}};
  int k = 2;  // 2
  matrix = {{2, 2, -1}};
  k = 3;  // 3
  matrix = {{5, -4, -3, 4}, {-3, -4, 4, 5}, {5, 1, 5, -4}};
  k = 8;  // 8

  cout << s.maxSumSubmatrix(matrix, k) << endl;
  return 0;
}
