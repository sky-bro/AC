#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int getSum(int a, int b) {
    unsigned XOR = a ^ b, OR = a | b;
    int res = 0;
    unsigned one_bit = 1;
    bool carry_bit = false;
    while (OR || carry_bit) {
      if (XOR & 1) {
        // 0 1
        if (!carry_bit) {
          res |= one_bit;
        }

      } else {
        // 1 1 or 0 0
        if (carry_bit) {
          res |= one_bit;
        }
        if (OR & 1) {
          carry_bit = true;
        } else {
          carry_bit = false;
        }
      }
      OR >>= 1;
      XOR >>= 1;
      one_bit <<= 1;
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  int a, b;
  Solution s;
  while (cin >> a >> b) {
    cout << s.getSum(a, b) << endl;
  }

  return 0;
}
