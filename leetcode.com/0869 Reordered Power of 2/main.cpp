#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool reorderedPowerOf2(int N) {
    int cnts[30][10];
    memset(cnts, 0, sizeof(cnts));
    for (int i = 0; i < 30; ++i) {
      int n = 1 << i;
      while (n) {
        cnts[i][n % 10]++;
        n /= 10;
      }
    }
    int cnt[10];
    memset(cnt, 0, sizeof(cnt));
    while (N) {
      cnt[N % 10]++;
      N /= 10;
    }
    for (int i = 0; i < 30; ++i) {
      int j = 0;
      for (; j < 10; ++j) {
        if (cnt[j] != cnts[i][j]) break;
      }
      if (j == 10) return true;
    }
    return false;
  }
};
