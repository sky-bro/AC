#include <bits/stdc++.h>

#include <type_traits>
using namespace std;
// clang-format off
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(0); return 0; } ();
#ifdef LOCAL_DEBUG
#include <competitive.h>
#else #define pp(...)
#define ppp(...)
#endif

template<class Fun> class y_combinator_result { Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); } };
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#define yc y_combinator
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define sz(x) (int((x).size()))
// clang-format on

int NO_EDGE = INT32_MAX;

// https://www.luogu.com.cn/problem/B3647
void solve() {
  // number of nodes and edges
  int n, m;
  cin >> n >> m;

  // all positive weights, use -1 to indicate no edge
  vector<vector<int>> G(n, vector<int>(n, NO_EDGE));
  vector<vector<int>> prev(n, vector<int>(n));

  for (int i = 0; i < n; ++i) {
    G[i][i] = 0;
  }
  for (int i = 0; i < m; ++i) {
    int from, to, weight;
    cin >> from >> to >> weight;
    --from;
    --to;
    G[from][to] = min(weight, G[from][to]);
    prev[from][to] = from;
    // non directed
    G[to][from] = min(weight, G[to][from]);
    prev[to][from] = to;
  }

  // floyd
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (G[i][k] != NO_EDGE && G[k][j] != NO_EDGE &&
            (G[i][j] == NO_EDGE || G[i][j] > G[i][k] + G[k][j])) {
          G[i][j] = G[i][k] + G[k][j];
          prev[i][j] = prev[k][j];
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << G[i][j] << " ";
    }
    cout << endl;
  }

#ifdef LOCAL_DEBUG
  // output node distances and prev
  pp(G);
  pp(prev);
#endif
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
