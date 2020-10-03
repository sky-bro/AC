#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = position.size();
    if (n == 0) return 0;
    for (int& pos : position) {
      pos = target - pos;
    }
    vector<int> ids(n);
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(),
         [&](int a, int b) { return position[a] < position[b]; });
    int res = 1;
    int pre_speed = speed[ids[0]];
    double pre_time = 1.0 * position[ids[0]] / pre_speed;
    for (int i = 1; i < n; ++i) {
      double cur_time = 1.0 * position[ids[i]] / speed[ids[i]];
      if (cur_time - pre_time > 1e-5) {
        pre_time = cur_time;
        ++res;
      }
    }
    return res;
  }
};
