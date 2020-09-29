#include <iostream>
#include <vector>

using namespace std;

int dp[1001] = {};

class Solution {
 public:
  bool divisorGame(int N) {
    if (dp[N]) return dp[N] == 1;
    if (N == 1) return false;
    for (int i = 1; i * i <= N; ++i) {
      if (N % i) continue;
      if (divisorGame(N - i) == false) {
        dp[N] = 1;
        return true;
      }
    }
    dp[N] = 2;
    return false;
  }
};
