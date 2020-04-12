#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

class Solution {
 private:
  inline bool valid_row(int r) {
    int a = r % 3, b = (r / 3) % 3, c = r / 9;
    if (a == b || b == c) return false;
    return true;
  }
  inline bool good_pair(int r1, int r2) {
    if (r1 % 3 == r2 % 3) return false;
    if ((r1 / 3) % 3 == (r2 / 3) % 3) return false;
    if (r1 / 9 == r2 / 9) return false;
    return true;
  }

 public:
  int numOfWays(int n) {
    // 0 1 2
    // R Y G
    vector<vector<long long>> dp(27, vector<long long>(n, 0));
    vector<int> rows;
    for (int i = 0; i < 27; ++i) {
      if (valid_row(i)) {
        rows.push_back(i);
        dp[i][0] = 1;
      }
    }
    for (int i = 1; i < n; ++i) {
      for (int r1 : rows) {
        long long cur = 0;
        for (int r2 : rows) {
          if (good_pair(r1, r2)) {
            cur += dp[r2][i - 1];
            cur %= MOD;
          }
        }
        dp[r1][i] = cur;
      }
    }
    long long res = 0;
    for (int r : rows) {
      res += dp[r][n - 1];
      res %= MOD;
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int n;
  while (cin >> n) {
    cout << s.numOfWays(n) << endl;
  }
  return 0;
}
