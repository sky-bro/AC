#include <iostream>
#include <vector>

using namespace std;

void solve(int case_num) {
  int N, K, P;
  scanf("%d%d%d", &N, &K, &P);
  vector<vector<int>> plates(N + 1, vector<int>(K + 1));
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= K; ++j) {
      scanf("%d", &plates[i][j]);
      plates[i][j] += plates[i][j - 1];
    }
  }
  vector<vector<int>> dp(N + 1, vector<int>(P + 1));
  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j <= P; ++j) {
      for (int k = 0; k <= min(j, K); ++k) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + plates[i][k]);
      }
    }
  }
  printf("Case #%d: %d\n", case_num, dp[N][P]);
}

int main(int argc, char const *argv[]) {
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; ++i) {
    solve(i);
  }
  return 0;
}