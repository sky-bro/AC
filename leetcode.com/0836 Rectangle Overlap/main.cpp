#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2,
                          bool done = false) {
    // corner inside another rec
    for (int i : {0, 2}) {
      for (int j : {1, 3}) {
        int x = rec1[i], y = rec1[j];
        if (x > rec2[0] && y > rec2[1] && x < rec2[2] && y < rec2[3])
          return true;
      }
    }
    // edge inside another rec
    // x1, x2
    if (rec1[0] < rec2[2] && rec1[0] >= rec2[0] ||
        rec1[2] <= rec2[2] && rec1[2] > rec2[0]) {
      if (!(rec1[1] >= rec2[3] || rec1[3] <= rec2[1])) return true;
    }
    // y1, y2
    if (rec1[1] < rec2[3] && rec1[1] >= rec2[1] ||
        rec1[3] <= rec2[3] && rec1[3] > rec2[1]) {
      if (!(rec1[0] >= rec2[2] || rec1[2] <= rec2[0])) return true;
    }
    if (done) return false;
    return isRectangleOverlap(rec2, rec1, true);
  }
};
