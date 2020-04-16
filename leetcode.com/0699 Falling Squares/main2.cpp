#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

#include "leetcode.hpp"

using namespace std;

// still offline propagation
// (multimap: from highest to lowest)
// even slower...? wtf!
class Solution {
 private:
  inline bool overlap(vector<int>& a, vector<int>& b) {
    return max((b[0] + b[1]) - a[0], (a[0] + a[1]) - b[0]) < a[1] + b[1];
  }

 public:
  vector<int> fallingSquares(vector<vector<int>>& positions) {
    int n = positions.size();
    vector<int> height(n);
    vector<int> res(n);
    multimap<int, int> h2i;  // height to index
    int cur_max = res[0] = height[0] = positions[0][1];
    h2i.emplace(positions[0][1], 0);
    for (int i = 1; i < n; ++i) {
      int pre_h = 0;
      // from the highest to lowest
      for (auto it = h2i.rbegin(); it != h2i.rend() && it->first > pre_h; ++it) {
        if (overlap(positions[i], positions[it->second])) {
          pre_h = height[it->second];
        }
      }
      h2i.emplace(height[i] = pre_h + positions[i][1], i);
      res[i] = cur_max = max(cur_max, height[i]);
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<int>> positions = {{100, 100}, {200, 100}};  // 100 100
  // positions = {{1, 2}, {2, 3}, {6, 1}}; // 2 5 5
  positions = {{2, 1}, {2, 9}, {1, 8}};  // 1 10 18
  printArr(s.fallingSquares(positions));
  return 0;
}
