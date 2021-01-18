#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

class Solution {
 private:
  int n, X, Y;
  bool ab;
  int f(const string &s, int l, int r) {
    if (r - l < 2) return 0;
    int res = 0;
    stack<char> stk;
    for (; l < r; ++l) {
      if (stk.empty()) {
        stk.push(s[l]);
        continue;
      }
      if (s[l] == 'a') {
        if (stk.top() == 'b' && !ab) {
          stk.pop();
          res += Y;
        } else {
          stk.push('a');
        }
      } else {  // 'b
        if (stk.top() == 'a' && ab) {
          stk.pop();
          res += X;
        } else {
          stk.push('b');
        }
      }
    }
    int a = 0, b = 0;
    while (!stk.empty()) {
      if (stk.top() == 'a')
        ++a;
      else
        ++b;
      stk.pop();
    }
    res += min(X, Y) * min(a, b);
    return res;
  }

 public:
  int maximumGain(string s, int x, int y) {
    int res = 0, n = s.size();
    X = x, Y = y;
    ab = X > Y;
    for (int i = 0; i < n - 1;) {
      while (i < n - 1 && s[i] != 'a' && s[i] != 'b') ++i;
      if (i >= n - 1) break;
      int j = i + 1;
      while (j < n && (s[j] == 'a' || s[j] == 'b')) ++j;
      res += f(s, i, j);
      i = j;
    }
    return res;
  }
};
