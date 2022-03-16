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

int A[10];
int vis[10];
int n;
void dfs(int k) {
  if (k == n) {
    for (int i = 0; i < n; ++i) {
      cout << setw(5) << A[i];
    }
    cout << "\n";
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      vis[i] = 1;
      A[k] = i + 1;
      dfs(k + 1);
      vis[i] = 0;
    }
  }
}
void solve() {
  cin >> n;
  fill(vis, vis + n, 0);
  dfs(0);
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
