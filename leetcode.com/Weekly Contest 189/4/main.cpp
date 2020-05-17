#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numPoints(vector<vector<int>>& points, int r) {
    int n = points.size();
    if (n < 2) return n;
    int ret = 1;
    typedef complex<double> V;
    const double eps = 1e-9;
    for (int i = 0; i < n; ++i) for (int j = i+1; j < n; ++j) if (i != j) {
      V p1(points[i][0], points[i][1]);
      V p2(points[j][0], points[j][1]);
      double d = abs(p2 - p1);
      if (d > r * 2) continue;
      V p3 = (p1 + p2) / 2.0;
      double h = sqrt(r * r - d * d / 4);
      V o = p3 + (p2 - p1) * V(0.0, 1.0) / d * h;
      int c = 2;
      for (int k = 0; k < n; ++k) {
        if (k != i && k != j && abs(V(points[k][0], points[k][1]) - o) < r + eps) ++c;
      }
      ret = max(ret, c);

      o = p3 - (p2 - p1) * V(0.0, 1.0) / d * h;
      c = 2;
      for (int k = 0; k < n; ++k) {
        if (k != i && k != j && abs(V(points[k][0], points[k][1]) - o) < r + eps) ++c;
      }
      ret = max(ret, c);
    }
    return ret;
  }
};

int main(int argc, char const *argv[])
{
  Solution s;
  vector<vector<int>> points = {{-2,0},{2,0},{0,2},{0,-2}};
  int r = 2; // 4
  points = {{-3,0},{3,0},{2,6},{5,4},{0,9},{7,8}};
  r = 5; // 5
  points = {{1,2},{3,5},{1,-1},{2,3},{4,1},{1,3}};
  r = 2; // 4
  points = {{-23,0},{23,22},{15,1},{-15,2},{30,-25},{2,19},{18,12},{9,21},{17,11},{20,-22},{-21,26},{25,0},{-18,15},{16,-18},{-5,-6},{10,4},{18,-20},{-19,-8},{-14,-28},{-5,3},{-16,-10},{-7,1}};
  r = 23; // 15
  points = {{23,22},{-15,2},{20,-22}};
  r = 23; // 2
  cout<<s.numPoints(points, r)<<endl;
  return 0;
}
