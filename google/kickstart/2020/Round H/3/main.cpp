#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

int N;
ll Xs[100000];
ll Ys[100000];

void solve(int case_num) {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> Xs[i] >> Ys[i];
  }
  sort(Xs, Xs + N);
  sort(Ys, Ys + N);
  for (int i = 0; i < N; ++i) {
    Xs[i] -= i;
  }
  sort(Xs, Xs + N);
  ll x = Xs[N / 2], y = Ys[N / 2];
  ll res = 0;
  for (int i = 0; i < N; ++i) {
    res += abs(Xs[i] - x) + abs(Ys[i] - y);
  }
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
