#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (true) {
          if (sx == tx && sy == ty) return true;
          if (tx < sx || ty < sy) return false;
          if (tx < ty) ty = min((ty - sy) % tx + sy, ty - tx);
          else if (tx > ty) tx = min((tx - sx) % ty + sx, tx - ty);
          else return false;
        }
    }
};
