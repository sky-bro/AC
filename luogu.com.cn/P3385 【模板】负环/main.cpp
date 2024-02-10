// https://www.luogu.com.cn/problem/P3385

#include <bits/stdc++.h>
#include <cstdint>
#include <queue>
using namespace std;
// clang-format off
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(0); return 0; } ();
#ifdef LOCAL_DEBUG
#include <competitive.h>
#else
#define pp(...)
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

bool solve() {
  int n, m, START = 1;
  cin >> n >> m;
  pp(n, m);
  vector<unordered_map<int, int>> graph(n + 1);
  for (int i = 0; i < m; ++i) {
    int s, t, w;
    cin >> s >> t >> w;
    graph[s][t] = graph[s].count(t) ? min(w, graph[s][t]) : w;
    if (w >= 0) {
      graph[t][s] = graph[t].count(s) ? min(w, graph[t][s]) : w;
    }
  }

  // the order (0 indexed) of a shortest path, if >= n, then negative cycle detected
  vector<int> cnt(n + 1);
  vector<int> dist(n + 1, INT32_MAX);
  dist[START] = 0;

  priority_queue<int> q;
  q.push(START);
  vector<bool> in_queue(n);
  while (!q.empty()) {
    int source = q.top();
    q.pop();
    in_queue[source] = false;
    // iterate through all neighbors
    for (auto neighborWeight: graph[source]) {
      // relaxation
      if (neighborWeight.second + dist[source] < dist[neighborWeight.first]) {
        dist[neighborWeight.first] = neighborWeight.second + dist[source];
        cnt[neighborWeight.first] = cnt[source] + 1;
        if (cnt[neighborWeight.first] >= n) {
          // loop detected
          return true;
        }
        if (!in_queue[neighborWeight.first]) {
          in_queue[neighborWeight.first] = true;
          q.push(neighborWeight.first);
        }
      }
    }
  }
  return false;
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
    int T; cin >> T;
    while (T--) {
      cout << (solve() ? "YES\n" : "NO\n");
    }
#ifdef LOCAL_DEBUG
  }
#endif
  return 0;
}
