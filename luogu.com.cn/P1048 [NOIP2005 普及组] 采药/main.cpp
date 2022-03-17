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

// 0-1 背包
void solve() {
  int T, M;
  cin >> T >> M;
  vector<int> dp(T + 1);
  while (M--) {
    int t, v;
    cin >> t >> v;
    for (int i = T; i >= t; --i) dp[i] = max(dp[i], dp[i - t] + v);
    pp(dp);
  }
  cout << *max_element(dp.begin(), dp.end()) << endl;
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
