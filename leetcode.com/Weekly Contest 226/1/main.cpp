#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

class Solution {
 public:
  int f(int x) {
    int res = 0;
    while (x) {
      res += x % 10;
      x /= 10;
    }
    return res;
  }
  int countBalls(int lowLimit, int highLimit) {
    vector<int> cnts(50);
    int res = 0;
    for (int i = lowLimit; i <= highLimit; ++i) {
      res = max(res, ++cnts[f(i)]);
    }
    return res;
  }
};
