#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

// n = 3
// d0 = 2*(a0+a1+a2)
// d1 = d0 + n(a1-a0) - (a1-a0)*(n-2) = d0 + 2(a1-a0)
// d2 = d1 + 4(a2-a1)                 = d1 + 4(a2-a1)

// di = d(i-1) + 2*i*(ai-a(i-1))
// d0 = 2(n*a0 + sum(a1-a0, .., ai-a0))

bool run_case() {
  int n;
  cin >> n;
  vector<ll> d(n * 2);
  for (int i = 0; i < n * 2; ++i) cin >> d[i];
  sort(d.begin(), d.end());
  for (int i = 1; i < 2 * n; i += 2) {
    if (d[i] != d[i - 1]) return false;
  }
  if (d[0] % 2) return false;
  // check a[i] - a[i-1]
  vector<ll> a(n);
  for (int i = 1; i < n; ++i) {
    if ((d[2 * i] - d[2 * i - 1]) % (2 * i)) return false;
    // distance from a0, for calculation of d0 later
    a[i] = a[i - 1] + (d[2 * i] - d[2 * i - 1]) / (2 * i);
    // a[i] - a[i-1] should not be 0
    if (a[i] == a[i - 1]) return false;
  }
  // check d0
  ll S = accumulate(a.begin(), a.end(), 0LL);
  S = d[0] / 2 - S;
  if (S <= 0 || S % n) return false;
  return true;
}

int main(int argc, char const *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    cout << (run_case() ? ("YES") : ("NO")) << endl;
  }
  return 0;
}
