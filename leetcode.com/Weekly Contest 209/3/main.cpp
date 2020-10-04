#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  double get_angle(vector<int>& a, vector<int>& b) {
    if (a[0] == b[0]) return a[1] > b[1] ? 90 : 270;
    double res = atan2((a[1] - b[1]), (a[0] - b[0])) / M_PI * 180;
    if (res < 0) return 360 + res;
    return res;
  }

 public:
  int visiblePoints(vector<vector<int>>& points, int angle,
                    vector<int>& location) {
    vector<double> angles;
    int res = 0;
    for (auto& p : points) {
      if (p[0] == location[0] && p[1] == location[1]) {
        ++res;
        continue;
      }
      angles.push_back(get_angle(p, location));
    }

    sort(angles.begin(), angles.end());
    int n = angles.size();
    int j = 1;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
      j = max(i + 1, j);
      int cur = 0;
      double angle_end = angles[i] + angle;
      if (angle_end >= 360) angle_end -= 360;
      for (; i != j % n; ++j) {
        double diff = angles[j % n] - angles[i];
        if (diff < 0) diff += 360;
        if (diff <= angle)
          cur++;
        else
          break;
      }
      mx = max(mx, j - i);
    }
    return res + mx;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<int>> points = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {1, 2}, {2, 1}};
  int angle = 0;
  vector<int> location = {1, 1};
  points = {{956, 232}, {438, 752}, {595, 297}, {508, 143}, {111, 594},
            {645, 824}, {758, 434}, {447, 423}, {825, 356}, {807, 377}};
  angle = 38;
  location = {74, 581};
  cout << s.visiblePoints(points, angle, location) << endl;
  return 0;
}
