#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

class Solution {
 public:
  int numWays(vector<string>& words, string target) {
    int n = words.size();
    int m = words[0].length();
    int target_len = target.length();
    vector<vector<long long>> d(m, vector<long long>(128));
    vector<int> lens(n);
    for (int i = 0; i < n; ++i) {
      lens[i] = words[i].length();
    }
    for (int i = 0; i < m; ++i) {
      for (int k = 0; k < n; ++k) {
        d[i][words[k][i]]++;
      }
    }
    vector<vector<long long>> dp(target_len, vector<long long>(m, 0));
    dp[target_len - 1][m - 1] = d[m - 1][target.back()];
    for (int k = m - 2; k >= target_len - 1; --k) {
      dp[target_len - 1][k] = dp[target_len - 1][k + 1];
      if (d[k][target.back()]) dp[target_len - 1][k] += d[k][target.back()];
      dp[target_len - 1][k] % MOD;
    }
    for (int i = target_len - 2; i >= 0; --i) {
      for (int k = m - 2; k >= i; --k) {
        if (d[k][target[i]])
          dp[i][k] =
              (d[k][target[i]] * dp[i + 1][k + 1] % MOD + dp[i][k + 1]) % MOD;
        else
          dp[i][k] = dp[i][k + 1] % MOD;
      }
    }
    return dp[0][0];
  }
};

int main(int argc, char const* argv[]) {
  vector<string> words = {"acca", "bbbb", "caca"};
  string target = "aba";
  //   words = {"abba","baab"};
  //   target = "bab";
  Solution s;
  cout << s.numWays(words, target) << endl;
  return 0;
}
