#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1e9 + 7;

class Solution {
 public:
  int kInversePairs(int n, int k) {
    if (k == 0) return 1;
    vector<vector<long long>> dp(n, vector<long long>(k + 1));
    for (int i = 0; i < n; ++i) dp[i][0] = 1;
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j <= k; ++j) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        int l = j - i - 1;
        if (l >= 0) dp[i][j] -= dp[i - 1][l];
        dp[i][j] = (dp[i][j] + MOD) % MOD;
        if (dp[i][j] == 0) break;
      }
    }
    return dp[n - 1][k];
  }
};

int main(int argc, char const *argv[]) {
  int n, k;
  Solution s;
  while (cin >> n >> k) {
    cout << s.kInversePairs(n, k) << endl;
  }
  return 0;
}
