#include <iostream>
#include <vector>

using namespace std;

unsigned f(unsigned x) {
  unsigned res = 0;
  for (x /= 5; x; x /= 5) res += x;
  return res;
}

class Solution {
 public:
  int preimageSizeFZF(int K) {
    unsigned l = 0, r = UINT32_MAX, m, k;
    // first find the right bound where f(rb) = K
    unsigned rb;
    while (l <= r) {
      m = r - (r - l) / 2;
      k = f(m);
      if (k < K) {
        l = m + 1;
      } else if (k == K) {
        l = m;
        if (l == r) break;
      } else {
        r = m - 1;
      }
    }
    if (l != r) return 0;
    rb = r;
    // then find the left bound where f(lb) = K
    l = 0, r = rb;
    while (l < r) {
      m = l + (r - l) / 2;
      k = f(m);
      if (k < K) {
        l = m + 1;
      } else {  // only k == K, no k > K
        r = m;
      }
    }
    unsigned lb = l;
    return rb - lb + 1;
  }
};

int main(int argc, char const *argv[]) {
  cout << f(UINT32_MAX) << endl;
  int K = 5;
  Solution s;
  while (cin >> K) {
    cout << s.preimageSizeFZF(K) << endl;
  }
  return 0;
}
