#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

typedef long long ll;

// O(N^2)
class Solution {
 private:
  int n;

 public:
  int numPermsDISequence(string s) {
    n = s.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    fill(dp[0].begin(), dp[0].end(), 1);
    for (int i = 0; i < n; ++i) {
      ll cur = 0;
      if (s[i] == 'D') {
        for (int j = n - 1 - i; j >= 0; --j) {
          cur = (cur + dp[i][j + 1]) % MOD;
          dp[i + 1][j] = cur;
        }
      } else {
        for (int j = 0; j < n - i; ++j) {
          cur = (cur + dp[i][j]) % MOD;
          dp[i + 1][j] = cur;
        }
      }
    }
    // ll res = 0;
    // for (int i = 0; i <= n; ++i) res = (res + dp[n][i]) % MOD;
    return dp[n][0];
  }
};

int main(int argc, char const *argv[]) {
  string S;
  Solution s;
  while (cin >> S) {
    cout << s.numPermsDISequence(S) << endl;
  }
  return 0;
}
