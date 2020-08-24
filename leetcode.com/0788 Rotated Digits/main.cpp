#include <iostream>

using namespace std;

class Solution {
 public:
  int rotatedDigits(int n) {
    int cnt = 0;
    for (int i = 2; i <= n; ++i) {
      int flag = 0;  // 0: undecided, 1: rotatedDigits, 2: not rotatedDigits
      int N = i;
      while (N) {
        switch (N % 10) {
          case 2:
          case 5:
          case 6:
          case 9:
            flag = 1;
            break;
          case 3:
          case 4:
          case 7:
            flag = 2;
            break;
        }
        N /= 10;
        if (flag == 2) break;
      }
      cnt += (flag == 1);
    }
    return cnt;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  cout << s.rotatedDigits(10) << endl;
  return 0;
}
