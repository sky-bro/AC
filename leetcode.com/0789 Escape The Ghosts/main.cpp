#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
    int dist = abs(target[0]) + abs(target[1]);
    return none_of(
        ghosts.begin(), ghosts.end(), [dist, &target](const auto& ghost) {
          return abs(ghost[0] - target[0]) + abs(ghost[1] - target[1]) <= dist;
        });
    // for (const auto& ghost : ghosts) {
    //   if (abs(ghost[0] - target[0]) + abs(ghost[1] - target[1]) <= dist)
    //     return false;
    // }
    // return true;
  }
};
