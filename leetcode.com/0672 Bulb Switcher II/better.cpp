#include <iostream>
#include <vector>

#include "leetcode.hpp"

using namespace std;

// ref: Java O(1)
// https://leetcode.com/problems/bulb-switcher-ii/discuss/107269/Java-O(1)
class Solution {
 public:
  // n and m both fit in range [0, 1000].
  int flipLights(int n, int m) {
    if (m == 0 || n == 0) return 1;
    if (n == 1) return 2;
    if (n == 2 && m == 1) return 3;
    if (n == 2) return 4;
    if (m == 1) return 4;
    if (m == 2) return 7;
    if (m >= 3) return 8;
    return 8;
  }
};

int main(int argc, char const *argv[]) {
  int m, n;
  Solution s;
  while (cin >> n >> m) {
    cout << s.flipLights(n, m) << endl;
  }
  return 0;
}
