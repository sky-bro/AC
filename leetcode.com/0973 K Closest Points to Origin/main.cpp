#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    vector<pair<int, int>> v;
    int n = points.size();
    for (int i = 0; i < n; ++i) {
      int s = points[i][0] * points[i][0] + points[i][1] * points[i][1];
      v.emplace_back(s, i);
    }
    nth_element(v.begin(), v.begin() + K - 1, v.end());
    vector<vector<int>> res;
    for (int i = 0; i < K; ++i) {
      res.push_back(points[v[i].second]);
    }
    return res;
  }
};
