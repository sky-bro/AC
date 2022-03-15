#include <bits/stdc++.h>
using namespace std;
// clang-format off
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(0); return 0; } ();
#ifdef LOCAL_DEBUG
#include <competitive.h>
#else
#define pp(...)
#define ppp(...)
#endif
// clang-format on

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> A(n + 1, vector<int>(m + 1)),
      B(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      cin >> A[i][j];
      B[i][j] = A[i][j] - B[i - 1][j - 1] + B[i - 1][j] + B[i][j - 1];
    }
  int l = 1, res = 0;
  while (l <= min(m, n)) {
    for (int i = l; i <= n; ++i) {
      for (int j = l; j <= m; ++j) {
        if (B[i][j] - B[i - l][j] - B[i][j - l] + B[i - l][j - l] == l * l) {
          res = l;
          break;
        }
      }
      if (res == l) break;
    }
    ++l;
  }
  cout << res << "\n";
}

int main() {
#ifdef LOCAL_DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int T0;
  cin >> T0;
  for (int t0 = 1; t0 <= T0; ++t0) {
    cout << "--------" << t0 << "--------\n";
#endif
    int T = 1;
    while (T--) {
      solve();
    }
#ifdef LOCAL_DEBUG
  }
#endif
  return 0;
}
