#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int flipgame(vector<int>& fronts, vector<int>& backs) {
    int n = fronts.size();
    unordered_set<int> bad_nums;
    for (int i = 0; i < n; ++i) {
      if (fronts[i] == backs[i]) bad_nums.insert(fronts[i]);
    }
    int res = INT32_MAX;
    for (int i = 0; i < n; ++i) {
      if (bad_nums.find(fronts[i]) == bad_nums.end()) res = min(res, fronts[i]);
      if (bad_nums.find(backs[i]) == bad_nums.end()) res = min(res, backs[i]);
    }
    return res == INT32_MAX ? 0 : res;
  }
};
