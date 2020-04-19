#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
class Solution {
  int N, M, K;
  vector<vector<int>> P;
  int dfs(int i, int m, int k, vector<vector<vector<int>>> &dp) {
    if (i == N) {
      if (k != K) return 0;
      return 1;
    }

    if (~dp[i][m][k]) return dp[i][m][k];
    long long res = 0;
    if (k == K) {
      if (k != K) return dp[i][m][k] = 0;
      res = P[m][N - i];
    } else {
      if (N - i < K - k || M - m < K - k) return dp[i][m][k] = 0;
      // next m ?
      if (N - i > K - k && m) {
        long long tmp = dfs(i + 1, m, k, dp);
        res += tmp*m;
        res %= MOD;
      }
      int nM = M - (K - k) + 1;
      for (int nm = m + 1; nm <= nM; ++nm) {
        res += dfs(i + 1, nm, k + 1, dp);
        res %= MOD;
      }
    }
    return dp[i][m][k] = res;
  }

 public:
  int numOfArrays(int n, int m, int k) {
    if (k == 0 || k > m) return 0;
    N = n;
    M = m;
    K = k;
    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
    P = vector<vector<int>>(m + 1, vector<int>(n, 1));
    for (int mm = 1; mm <= m; ++mm) {
      for (int i = 1; i < n; ++i) {
        P[mm][i] = (long long)(P[mm][i - 1]) * mm % MOD;
      }
    }
    dfs(0, 0, 0, dp);
    return dp[0][0][0];
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int n, m, k;
  while (cin >> n >> m >> k) {
    cout << s.numOfArrays(n, m, k) << endl;
  }
  return 0;
}
