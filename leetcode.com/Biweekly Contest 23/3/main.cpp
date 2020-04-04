#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  bool check_corner(int x, int y, int radius, int x_center, int y_center) {
    double x_d = x - x_center, y_d = y - y_center;
    return x_d * x_d + y_d * y_d <= radius * radius;
  }

 public:
  bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1,
                    int x2, int y2) {
    double x_center1 = (x1 + x2) / 2.0, y_center1 = (y1 + y2) / 2.0;
    double x_d = abs(x_center - x_center1);
    double y_d = abs(y_center - y_center1);
    double center_dis = sqrt(x_d * x_d + y_d * y_d);
    if (center_dis <= radius + min(abs(x_center1 - x1), abs(y_center1 - y1)))
      return true;
    if (check_corner(x1, y1, radius, x_center, y_center) ||
        check_corner(x1, y2, radius, x_center, y_center) ||
        check_corner(x2, y2, radius, x_center, y_center) ||
        check_corner(x2, y1, radius, x_center, y_center))
      return true;
    
    int lb = x_center - radius;
    int rb = x_center + radius;
    int tb = y_center + radius;
    int bb = y_center - radius;
    if (y1 <= tb && y1 >= bb && x1 <= x_center && x2 >= x_center) return true;
    if (y2 <= tb && y2 >= bb && x1 <= x_center && x2 >= x_center) return true;
    if (x1 <= rb && x1 >= lb && y1 <= y_center && y2 >= y_center) return true;
    if (x2 <= rb && x2 >= lb && y1 <= y_center && y2 >= y_center) return true;
    return false;
  }
};