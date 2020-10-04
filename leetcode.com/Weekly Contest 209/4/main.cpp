#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  map<int, int> dp;
  map<int, int> dp2;
  int f(int n) {
    int N = n;
    if (dp.find(n) != dp.end()) return dp[n];
    unsigned mask = 1 << 31;
    int cnt = 0;
    while (mask) {
      mask >>= 1;
      if ((n & mask) == 0) continue;
      if (n & (mask >> 1)) {
        cnt += f(n & ((mask >> 1) - 1)) + 1 + f(mask >> 1);
        break;
      } else {
        cnt += f2(n, mask >> 1) + 1 + f(mask >> 1);
        break;
      }
    }
    return dp[N] = cnt;
  }
  int f2(int n, int mask) {
    int res = 0;
    if (mask == 1) return 1;
    if ((mask >> 1) & n) {
      res += f(n & ((mask >> 1) - 1)) + 1 + f(mask >> 1);
    } else {
      res += f2(n, mask >> 1) + 1 + f(mask >> 1);
    }
    return res;
  }

 public:
  int minimumOneBitOperations(int n) {
    dp.clear();
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 2;
    dp2.clear();
    return f(n);
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int n;
  while (cin >> n) {
    cout << s.minimumOneBitOperations(n) << endl;
  }
  return 0;
}
