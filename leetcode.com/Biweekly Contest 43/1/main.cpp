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
  int totalMoney(int n) {
    int inc = 0;
    int res = (28 + 28 + (n / 7 - 1) * 7) * (n / 7) / 2;
    inc += n / 7;
    n %= 7;
    res += (inc + 1 + inc + n) * n / 2;
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int n;
  while (cin >> n) {
    cout << s.totalMoney(n) << endl;
  }
  return 0;
}
