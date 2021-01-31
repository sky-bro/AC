#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

int main(int argc, char const *argv[]) {
  int t, n, x;
  cin >> t;
  while (t--) {
    cin >> n;
    int mx = 1, cur = 0;
    int pre = 0;
    for (int i = 0; i < n; ++i) {
      cin >> x;
      if (x == pre) {
        mx = max(++cur, mx);
      } else {
        cur = 1;
      }
      pre = x;
    }
    cout << mx << endl;
  }
  return 0;
}
