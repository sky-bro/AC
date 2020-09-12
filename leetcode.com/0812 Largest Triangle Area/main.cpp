#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  double largestTriangleArea(vector<vector<int>>& points) {
    int n = points.size();
    double res = 0;
    for (int i = 0; i < n - 2; ++i) {
      int x1 = points[i][0], y1 = points[i][1];
      for (int j = i + 1; j < n - 1; ++j) {
        int x2 = points[j][0], y2 = points[j][1];
        for (int k = j + 1; k < n; ++k) {
          int x3 = points[k][0], y3 = points[k][1];
          res = max(res, abs(.5 * (x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 -
                                   x2 * y1 - x3 * y2)));
        }
      }
    }
    return res;
  }
};
