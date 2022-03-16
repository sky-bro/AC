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

int n, m;
typedef long long ll;

void solve() {
  cin >> n >> m;
  vector<ll> G(n);
  map<ll, int> cnts;
  cnts[0] = 0;
  G[0] = 1;
  for (int i = 1; i < n; ++i) G[i] = G[i - 1] << 1;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    G[a] |= (1ll << b);
    G[b] |= (1ll << a);
  }
  for (int i = 0; i < (1 << (n / 2)); ++i) {
    ll t = 0;
    int cnt = 0;
    for (int j = 0; j < n / 2; ++j) {
      if (i & (1 << j)) {
        ++cnt;
        t ^= G[j];
      }
    }
    if (cnts.count(t) == 0)
      cnts[t] = cnt;
    else
      cnts[t] = min(cnts[t], cnt);
  }

  int res = INT32_MAX;
  for (int i = 0; i < (1 << (n - n / 2)); ++i) {
    ll t = (1ll << n) - 1;
    int cnt = 0;
    for (int j = 0; j < (n - n / 2); ++j) {
      if (i & (1 << j)) {
        ++cnt;
        t ^= G[n / 2 + j];
      }
    }
    if (cnts.count(t)) {
      pp(res, t, cnts[t], cnt);
      res = min(res, cnt + cnts[t]);
    }
  }
  cout << res << endl;
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
