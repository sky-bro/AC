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
  int n;
  cin >> n;
  vector<int> A(n + 1), B(n + 1);
  stack<int> stk;
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
    while (!stk.empty() && A[stk.top()] < A[i]) {
      B[stk.top()] = i;
      stk.pop();
    }
    stk.push(i);
  }
  for (int i = 1; i <= n; ++i) cout << B[i] << " ";
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
