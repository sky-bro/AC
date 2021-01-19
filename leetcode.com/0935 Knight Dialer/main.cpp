#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
typedef long long ll;

ll dp[2][10];

/*
1 2 3
4 5 6
7 8 9
* 0 #
*/

class Solution {
 public:
  int knightDialer(int n) {
    fill(dp[0], dp[0] + 10, 1);
    int i = 0;
    while (--n) {
      int ni = i ^ 1;
      dp[ni][0] = (dp[i][4] + dp[i][6]) % MOD;
      dp[ni][1] = (dp[i][6] + dp[i][8]) % MOD;
      dp[ni][2] = (dp[i][7] + dp[i][9]) % MOD;
      dp[ni][3] = (dp[i][4] + dp[i][8]) % MOD;
      dp[ni][4] = (dp[i][0] + dp[i][3] + dp[i][9]) % MOD;
      dp[ni][5] = 0;
      dp[ni][6] = (dp[i][0] + dp[i][1] + dp[i][7]) % MOD;
      dp[ni][7] = (dp[i][2] + dp[i][6]) % MOD;
      dp[ni][8] = (dp[i][1] + dp[i][3]) % MOD;
      dp[ni][9] = (dp[i][2] + dp[i][4]) % MOD;
      i = ni;
    }
    return accumulate(dp[i], dp[i] + 10, 0,
                      [](ll a, ll b) { return (a + b) % MOD; });
  }
};
