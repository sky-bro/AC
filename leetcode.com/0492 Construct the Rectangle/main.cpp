#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
 public:
  vector<int> constructRectangle(int area) {
    for (int W = sqrt(area);; --W) {
      if (area % W == 0) return {area / W, W};
    }
  }
};