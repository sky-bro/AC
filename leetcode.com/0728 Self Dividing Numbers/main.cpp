#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> selfDividingNumbers(int left, int right) {
    vector<int> res;
    auto chk = [&]() {
      int num = left;
      while (num) {
        int r = num % 10;
        if (r == 0 || left % r) return false;
        num /= 10;
      }
      return true;
    };
    for (; left <= right; ++left) {
      if (chk()) {
        res.push_back(left);
      }
    }
    return res;
  }
};
