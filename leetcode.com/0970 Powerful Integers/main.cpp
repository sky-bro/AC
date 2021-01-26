#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;
class Solution {
 public:
  vector<int> powerfulIntegers(int x, int y, int bound) {
    if (bound == 0) return {};
    unordered_set<int> res;
    ll X = 1;
    while (X <= bound) {
      ll Y = 1;
      while (X + Y <= bound) {
        res.insert(Y + X);
        Y *= y;
        if (y == 1) break;
      }
      X *= x;
      if (x == 1) break;
    }
    return vector<int>(res.begin(), res.end());
  }
};
