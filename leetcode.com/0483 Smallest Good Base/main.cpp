#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// ref:
// https://leetcode.com/problems/smallest-good-base/discuss/96587/Python-solution-with-detailed-mathematical-explanation-and-derivation
// ref:
// https://leetcode.com/problems/smallest-good-base/discuss/96590/3ms-AC-C++-long-long-int-+-binary-search
class Solution {
 public:
  string smallestGoodBase(string n) {
    uint64_t num = stoull(n);
    // m: number of 1s - 1
    // for (int m = int(log2(num)); m >= 1; --m) {  // if m == 1, return
    for (int m = int(log2(num)); m > 1; --m) {  // if m == 1, return
      // when n = "1000000000000000000"
      // pow(num-1, 1) = "1000000000000000000" ...
      // so when m = 1, return n-1
      uint64_t sum = 1, base = uint64_t(pow(num - 1, 1.0 / m)), cur = 1;
      for (int i = 0; i < m; ++i) {
        sum += (cur *= base);
      }
      if (sum == num) return to_string(base);
    }
    return to_string(num - 1);
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string n;
  while (cin >> n) {
    cout << s.smallestGoodBase(n) << endl;
  }
  return 0;
}
