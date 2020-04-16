#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#include "leetcode.hpp"

using namespace std;

// for this problem, if we know the coordinate compression
// we can just brute force it in O(2000*2000) time
// or use segment tree: gives O(nlogn) time

// official solution (4 different solutions): https://leetcode.com/articles/falling-squares/
// Approach 1: Offline Propagation
// Approach 2: Brute Force with Coordinate Compression
// Approach 3: Block (Square Root) Decomposition
// Approach 4: Segment Tree with Lazy Propagation

// 1. offline propagation O(N^2) time, O(N) space
class Solution {
 private:
  inline bool overlap(vector<int>& a, vector<int>& b) {
    return max((b[0] + b[1]) - a[0], (a[0] + a[1]) - b[0]) < a[1] + b[1];
  }

 public:
  vector<int> fallingSquares(vector<vector<int>>& positions) {
    int n = positions.size(), cur_max;
    vector<int> height(n);
    vector<int> res(n);
    cur_max = res[0] = height[0] = positions[0][1];
    for (int i = 1; i < n; ++i) {
      int prev_height = 0;
      for (int j = 0; j < i; ++j) {
        if (height[j] > prev_height && overlap(positions[i], positions[j])) {
          prev_height = height[j];
        }
      }
      res[i] = cur_max = max(cur_max, height[i] = prev_height + positions[i][1]);
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<int>> positions = {{100, 100}, {200, 100}};  // 100 100
  printArr(s.fallingSquares(positions));
  return 0;
}
