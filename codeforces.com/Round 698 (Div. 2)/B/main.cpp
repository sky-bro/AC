#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

bool dp[10][100];
void init() {
  for (int i = 1; i < 10; ++i) {
    dp[i][0] = true;
    for (int j = i; j < 100; j += 10) {
      for (int k = j; k < 100; ++k) {
        dp[i][k] |= dp[i][k - j];
      }
    }
    for (int j = i * 10; j < (i + 1) * 10; ++j) {
      for (int k = j; k < 100; ++k) {
        dp[i][k] |= dp[i][k - j];
      }
    }
  }
}

bool chk(int x, int d) {
  if (x >= 100) return true;
  return dp[d][x];
}

int main(int argc, char const *argv[]) {
  int T;
  cin >> T;
  init();
  while (T--) {
    int n, x, d;
    cin >> n >> d;
    while (n--) {
      cin >> x;
      if (chk(x, d)) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
  return 0;
}
