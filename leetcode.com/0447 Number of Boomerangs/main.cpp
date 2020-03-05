#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// ref: C++ clean solution O(n^2). Fully commented and explained.
// https://leetcode.com/problems/number-of-boomerangs/discuss/92866/C%2B%2B-clean-solution-O(n2).-Fully-commented-and-explained.
class Solution {
 public:
  int numberOfBoomerangs(vector<vector<int>> &points) {
    int n = points.size(), res = 0;
    for (auto &point0 : points) {
      unordered_map<int, int> cnt;
      for (auto &point1 : points) {
        int d0 = point0[0] - point1[0];
        int d1 = point0[1] - point1[1];
        ++cnt[d0 * d0 + d1 * d1];
      }
      for (auto &p : cnt) {
        res += p.second * (p.second - 1);
      }
    }
    return res;
  }
};