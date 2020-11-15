#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

ll pows[20];
ll sums[20];

ll cnt(ll x) {
  if (x == 0) return 0;
  string s = to_string(x);
  int n = s.length();
  ll res = sums[n - 1];
  for (int i = 0; i < n; ++i) {
    if (i & 1) {               // even
      if ((s[i] - '0') & 1) {  // odd
        res += ((s[i] - '0') / 2 + 1) * pows[n - i - 1];
        break;
      } else {
        res += ((s[i] - '0') / 2) * pows[n - i - 1];
        if (i == n - 1) ++res;
      }
    } else {                   // odd
      if ((s[i] - '0') & 1) {  // odd
        res += ((s[i] - '0') / 2) * pows[n - i - 1];
        if (i == n - 1) ++res;
      } else {
        res += ((s[i] - '0') / 2) * pows[n - i - 1];
        break;
      }
    }
  }
  return res;
}

void solve(int case_num) {
  ll L, R;
  cin >> L >> R;
  cout << cnt(R) - cnt(L - 1) << "\n";
}

int main(int argc, char const *argv[]) {
  pows[0] = 1;
  sums[0] = 0;
  for (int i = 1; i <= 19; ++i) {
    pows[i] = 5 * pows[i - 1];
    sums[i] = pows[i] + sums[i - 1];
  }
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << "Case #" << t << ": ";
    solve(t);
  }
  return 0;
}

/*
5
5 15
120 125
779 783
1 10
1000 10000
*/