#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

string S = "aeiouAEIOU";
class Solution {
 public:
  bool halvesAreAlike(string s) {
    int n = s.size();
    int a = 0, b = 0;
    for (int i = 0; i < n / 2; ++i) {
      for (int j = 0; j < 10; ++j) {
        if (S[j] == s[i]) {
          ++a;
          break;
        }
      }
    }
    for (int i = n / 2; i < n; ++i) {
      for (int j = 0; j < 10; ++j) {
        if (S[j] == s[i]) {
          ++b;
          break;
        }
      }
    }
    return a == b;
  }
};
