#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

class Solution {
 public:
  int minimumBoxes(int n) {
    ll sum = 1, base = 1, row = 1;

    while (sum < n) {
      base += (++row);
      sum += base;
    }
    while (sum > n) {
      --base;
      sum -= (row--);
      if (sum < n) return base + 1;
    }
    return base;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int n;
  while (cin >> n) cout << s.minimumBoxes(n) << endl;
  return 0;
}
