#include <iostream>
#include <vector>

using namespace std;

// for 1D:
// left1 < right2 && left2 < right1

// for 2D:
// overlap on both x and y

class Solution {
 public:
  bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    // overlap on x && overlap on y
    return rec1[0] < rec2[2] && rec2[0] < rec1[2] && rec1[1] < rec2[3] &&
           rec2[1] < rec1[3];
  }
};
