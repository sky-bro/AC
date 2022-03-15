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
  vector<pair<int, int>> A(n);
  vector<int> B(n);
  stack<int> stk;
  for (int i = 0; i < n; ++i) {
    cin >> A[i].first >> A[i].second;
    while (!stk.empty() && A[stk.top()].first < A[i].first) {
      // accumulate left side of i
      // depends on A[i], use A[stk.top()] only once
      B[i] += A[stk.top()].second;
      stk.pop();
    }
    stk.push(i);
  }
  stk = stack<int>();
  for (int i = n - 1; i >= 0; --i) {
    while (!stk.empty() && A[stk.top()].first < A[i].first) {
      // accumulate right side of i
      // depends on A[i], use A[stk.top()] only once
      B[i] += A[stk.top()].second;
      stk.pop();
    }
    stk.push(i);
  }
  cout << *max_element(B.begin(), B.end()) << "\n";
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
