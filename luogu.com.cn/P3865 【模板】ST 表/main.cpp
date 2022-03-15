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

int n, M;
const int maxn = 1e5;
const int maxLogn = 21;
// sparseTree[i][j] = query(i, i + (1 << j) - 1);
int sparseTree[maxn][maxLogn + 1], Logn[maxn + 1];

inline void computeLogn() {
  Logn[1] = 0;
  for (int i = 2; i <= maxn; ++i) Logn[i] = Logn[i / 2] + 1;
}

void buildSparseTree() {
  for (int i = 0; i < n; ++i) cin >> sparseTree[i][0];
  computeLogn();
  for (int j = 1; j <= maxLogn; ++j) {
    for (int i = 0; i + (1 << j) - 1 < n; ++i) {
      sparseTree[i][j] =
          max(sparseTree[i][j - 1], sparseTree[i + (1 << (j - 1))][j - 1]);
    }
  }
}

// query for range [l, r]
inline int query(int l, int r) {
  int logn = Logn[r - l + 1];
  return max(sparseTree[l][logn], sparseTree[r - (1 << logn) + 1][logn]);
}

void solve() {
  cin >> n >> M;
  int l, r;
  buildSparseTree();
  while (M--) {
    cin >> l >> r;
    // do not use endl: https://stackoverflow.com/a/43052032
    cout << query(l - 1, r - 1) << "\n";
  }
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
