#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
 private:
  int n, K;
  string s;
  int dfs(int i, vector<int> &dp) {
    if (i == n) return 1;
    if (~dp[i]) return dp[i];
    long long res = 0;
    if (s[i] == '0') return dp[i] = 0;
    for (int j = 1; i + j <= n; ++j) {
      long long num = stoll(s.substr(i, j));
      if (num > K) break;
      res += dfs(i + j, dp);
      res %= MOD;
    }
    return dp[i] = res;
  }

 public:
  int numberOfArrays(string s, int k) {
    n = s.length();
    K = k;
    this->s = s;
    vector<int> dp(n, -1);
    dfs(0, dp);
    return dp[0];
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  string s;
  int k;
  while (cin >> s >> k) {
    cout << sol.numberOfArrays(s, k) << endl;
  }
  return 0;
}
