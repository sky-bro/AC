#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maximumSwap(int num) {
    vector<int> digits;
    int m = 0;
    while (num) {
      digits.push_back(num % 10);
      m = max(m, digits.back());
      num /= 10;
    }

    for (int i = digits.size() - 1; i > 0; --i) {
      int l = i;
      for (int j = 0; j < i; ++j) {
        if (digits[j] > digits[l]) l = j;
      }
      if (l != i) {
        swap(digits[i], digits[l]);
        break;
      }
    }

    int res = 0;
    for (int i = digits.size() - 1; i >= 0; --i) {
      res = res * 10 + digits[i];
    }
    return res;
  }
};
