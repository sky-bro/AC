#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

class Solution {
 public:
  int numTilings(int N) {
    // a b c :
    /*
      [x]      or [x]  [x][x]
      [x], [x]       , [y][y]
    */
    int a = 1, b = 0, c = 0;
    int a_prev = 0, c_prev = 0;
    while (N--) {
      int a_prev_tmp = a;
      int c_prev_tmp = c;
      a = ((a + b) % MOD + c) % MOD;
      b = ((a_prev * 2 % MOD + b) % MOD + c_prev * 2 % MOD) % MOD;
      c = (a_prev + c_prev) % MOD;
      a_prev = a_prev_tmp;
      c_prev = c_prev_tmp;
    }
    return (a + c) % MOD;
  }
};

int main(int argc, char const *argv[]) {
  /*
  N = 1 ~ 7 :
    1
    2
    5
    11
    24
    53
    117
  */
  int N = 3;
  Solution s;
  while (cin >> N) {
    cout << s.numTilings(N) << endl;
  }
  return 0;
}
