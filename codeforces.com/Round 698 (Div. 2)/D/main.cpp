#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

// 2x - y = x - (y - x)
// this is the mirror reflection of y over x
// --------y'---x---y---------

bool run_case() {
  ll n, k, d;
  cin >> n >> k;
  vector<ll> A(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  d = A[1] - A[0];
  for (int i = 2; i < n; ++i) {
    d = gcd(d, A[i] - A[i - 1]);
  }
  if ((k - A[0]) % d) return false;
  return true;
}

int main(int argc, char const *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    cout << (run_case() ? "YES" : "NO") << endl;
  }
  return 0;
}
