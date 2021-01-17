#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

class Solution {
 public:
  int countGoodRectangles(vector<vector<int>> &rectangles) {
    int res = 0;
    int mx = min(rectangles[0][0], rectangles[0][1]);
    for (auto &v : rectangles) {
      mx = max(mx, min(v[0], v[1]));
    }
    for (auto &v : rectangles) {
      res += (min(v[0], v[1]) >= mx);
    }
    return res;
  }
};
