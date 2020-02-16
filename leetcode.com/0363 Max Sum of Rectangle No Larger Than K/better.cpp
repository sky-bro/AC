#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

// ref:
// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/discuss/83599/Accepted-C%2B%2B-codes-with-explanation-and-references
class Solution {
  int ans = INT32_MIN;

 public:
  int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    int rows = matrix.size();
    if (rows == 0) return ans;
    int cols = matrix[0].size();

    for (int i = 0; i < cols; ++i) {
      vector<int> nums(rows, 0);
      for (int x = i; x < cols; ++x) {
        for (int y = 0; y < rows; ++y) {
          nums[y] += matrix[y][x];
        }
        handle1DArray(nums, k);
        if (ans == k) return ans;
      }
    }

    return ans;
  }

  void handle1DArray(vector<int>& nums, int k) {
    int sum = 0, maxS = INT32_MIN;
    // Kadane's Algorithm
    // it's a trick. Maybe O(n) to solve this problem
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      maxS = max(sum, maxS);
      if (sum == k) {
        ans = k;
        return;
      }
      if (sum < 0) sum = 0;
    }
    if (maxS <= k) {
      ans = max(ans, maxS);
      return;
    }

    vector<int> sums;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < sums.size(); ++j) {
        sums[j] += nums[i];
        if (sums[j] <= k && sums[j] > ans) ans = sums[j];
      }
      sums.push_back(nums[i]);
      if (nums[i] <= k && nums[i] > ans) ans = nums[i];
    }
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
