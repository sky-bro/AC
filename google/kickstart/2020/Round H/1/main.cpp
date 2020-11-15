#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

void solve(int case_num) {
  ll N, K, S;
  cin >> N >> K >> S;

  ll res = min(K + (K - S) + (N - S), K + N);
  cout << res << "\n";
}

int main(int argc, char const *argv[]) {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << "Case #" << t << ": ";
    solve(t);
  }
  return 0;
}
