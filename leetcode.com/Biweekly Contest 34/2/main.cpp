#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

class Solution {
 public:
  int numWays(string s) {
    long long n = s.length();
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') ++cnt;
    }
    if (cnt % 3) return 0;
    if (cnt == 0) return (n - 1) * (n - 2) / 2 % MOD;
    long long a, b, c, d;
    for (int i = 0, t = 0; i < n; ++i) {
      if (s[i] == '1') ++t;
      if (t == cnt / 3) {
        a = i;
        break;
      }
    }
    for (int i = a + 1; i < n; ++i) {
      if (s[i] == '1') {
        b = i;
        break;
      }
    }
    for (int i = b, t = 0; i < n; ++i) {
      if (s[i] == '1') ++t;
      if (t == cnt / 3) {
        c = i;
        break;
      }
    }
    for (int i = c + 1; i < n; ++i) {
      if (s[i] == '1') {
        d = i;
        break;
      }
    }
    return (b - a) * (d - c) % MOD;
  }
};
