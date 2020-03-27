#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int leastBricks(vector<vector<int>>& wall) {
    int N = wall.size(), res = N;
    unordered_map<int, int> m;
    for (auto& r : wall) {
      int n = r.size();
      for (int i = 0, w = r[0]; i < n - 1; ++i, w += r[i]) ++m[w];
    }
    for (auto& p : m) res = min(res, N - p.second);
    return res;
  }
};