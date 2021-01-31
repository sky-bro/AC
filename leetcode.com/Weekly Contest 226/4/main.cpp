#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

bool dp[2010][1010];
bool dp2[2010][1010];
class Solution {
 public:
  bool checkPartitioning(string s) {
    int n = s.size();
    s.push_back('.');
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) {
    }
    for (int i = 0; i < n; ++i) {
      dp[i][0] = true;
      dp2[i][1] = (s[i + 1] == s[i]);
      for (int j = 1; i - j >= 0 && i + j < n; ++j) {
        dp[i][j] = dp[i][j - 1] && (s[i - j] == s[i + j]);
        dp2[i][j + 1] = dp2[i][j] && (s[i - j] == s[i + j + 1]);
      }
    }
    auto chk = [&](int l, int r) {
      int len = r - l;
      if (len & 1) {
        return dp[len / 2 + l][len / 2];
      } else {
        return dp2[len / 2 + l - 1][len / 2];
      }
    };
    for (int i = 1; i <= n - 2; ++i) {
      for (int j = i + 1; j <= n - 1; ++j) {
        if (chk(0, i) && chk(i, j) && chk(j, n)) {
          return true;
        }
      }
    }
    return false;
  }
};
