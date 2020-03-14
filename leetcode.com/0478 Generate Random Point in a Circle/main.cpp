#include <iostream>
#include <vector>
#include <cmath>
#include <random>

using namespace std;

// ref: C++生成浮点随机数 https://www.cnblogs.com/zealousness/p/10324170.html
// ref: Polar Coordinates 10 lines
// https://leetcode.com/problems/generate-random-point-in-a-circle/discuss/154037/Polar-Coordinates-10-lines
random_device rd;
mt19937 gen(rd());
uniform_real_distribution<> dis(0, 1);
class Solution {
 private:
  double r;     // radius
  double x, y;  // center

 public:
  Solution(double radius, double x_center, double y_center)
      : r(radius), x(x_center), y(y_center) {}

  vector<double> randPoint() {
    double len = sqrt(dis(gen)) * r;
    double deg = dis(gen) * 2 * M_PI;
    vector<double> res;
    res.push_back(x + len * cos(deg));
    res.push_back(y + len * sin(deg));
    return res;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */