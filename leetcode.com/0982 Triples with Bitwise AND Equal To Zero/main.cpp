#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int dp[1 << 16];

class Solution {
 public:
  int countTriplets(vector<int>& A) {
    int res = 0;
    memset(dp, 0, sizeof(dp));
    for (int a : A) {
      for (int b : A) {
        ++dp[a & b];
      }
    }
    for (int c : A) {
      for (int ab = 0; ab < (1 << 16); ++ab) {
        if (!(c & ab)) res += dp[ab];
      }
    }
    return res;
  }
};
