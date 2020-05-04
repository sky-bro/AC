#include <iostream>
#include <vector>

using namespace std;

// ref: 665772
// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/discuss/113232/665772

static vector<bool> a = [](){
  vector<bool> res(33);
  res[2] = res[3] = res[5] = res[7] = res[11] = res[13] = res[17] = res[19] = res[23] = res[29] = res[31] = true;
  return res;
}();

class Solution {
private:
  bool chk(int num) {
    num = __builtin_popcount(num);
    if (num <= 1) return false;
    for (int i = 2; i < num; ++i) {
      if (num % i == 0) return false;
    }
    return true;
  }
public:
    int countPrimeSetBits(int L, int R) {
        int res = 0;
        while (L <= R) {
          // if (chk(L)) ++res;
          // if (a[__builtin_popcount(L)]) ++res;
          res += 665772 >> __builtin_popcount(L++) & 1;
          // ++L;
        }
        return res;
    }
};
