#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int integerReplacement(int n) {
    int res = 0;
    unsigned m = n;
    for (; m != 1; ++res) {
      if (m & 1) {
        // odd
        if (m == 3) return 2 + res;
        if (m & 2) {
          // ...11
          ++m;
        } else {
          // ...01
          --m;
        }
      } else {
        m >>= 1;
      }
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int n;
  while (cin >> n) {
    cout << s.integerReplacement(n) << endl;
  }
  return 0;
}
