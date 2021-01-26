#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  double minAreaFreeRect(vector<vector<int>>& points) {
    set<vector<int>> st(points.begin(), points.end());
    int n = points.size();
    double res = 2e9;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        for (int k = j + 1; k < n; ++k) {
          vector<int> a = {points[j][0] - points[k][0],
                           points[j][1] - points[k][1]},
                      b = {points[i][0] - points[k][0],
                           points[i][1] - points[k][1]},
                      c = {points[j][0] - points[i][0],
                           points[j][1] - points[i][1]},
                      d(2);
          // i
          if (b[0] * c[0] + b[1] * c[1] == 0) {
            d[0] = points[j][0] - b[0];
            d[1] = points[j][1] - b[1];
            if (st.find(d) != st.end()) {
              res = min(res, sqrt(1.0 * (b[0] * b[0] + b[1] * b[1]) *
                                  (c[0] * c[0] + c[1] * c[1])));
              continue;
            }
          }
          // j
          if (a[0] * c[0] + a[1] * c[1] == 0) {
            d[0] = points[i][0] - a[0];
            d[1] = points[i][1] - a[1];
            if (st.find(d) != st.end()) {
              res = min(res, sqrt(1.0 * (a[0] * a[0] + a[1] * a[1]) *
                                  (c[0] * c[0] + c[1] * c[1])));
              continue;
            }
          }
          // k
          if (b[0] * a[0] + b[1] * a[1] == 0) {
            d[0] = points[j][0] + b[0];
            d[1] = points[j][1] + b[1];
            if (st.find(d) != st.end()) {
              res = min(res, sqrt(1.0 * (b[0] * b[0] + b[1] * b[1]) *
                                  (a[0] * a[0] + a[1] * a[1])));
              continue;
            }
          }
        }
      }
    }
    return res == 2e9 ? 0 : res;
  }
};
