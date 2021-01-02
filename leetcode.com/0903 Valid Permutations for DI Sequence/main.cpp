#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

typedef long long ll;

// O(N^3)
class Solution {
 private:
  int n;
  /**
   * @param l # smaller numbers
   * @param i filling i-th number
   */
  int f(int l, int i, vector<vector<ll>> &dp, const string &s) {
    if (i == n) {  // last number, l = 0 or 1
      if (s[i - 1] == 'D') {
        return l;
      } else {
        return 1 - l;
      }
    }
    if (~dp[l][i]) return dp[l][i];
    ll res = 0;
    if (s[i - 1] == 'D') {
      for (int ll = 0; ll < l; ++ll) {
        res = (res + f(ll, i + 1, dp, s)) % MOD;
      }
    } else {
      for (int ll = l; ll <= n - i; ++ll) {
        res = (res + f(ll, i + 1, dp, s)) % MOD;
      }
    }
    return dp[l][i] = res;
  }

 public:
  int numPermsDISequence(string s) {
    n = s.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(n, -1));
    ll res = 0;
    for (int l = 0; l <= n; ++l) {
      res = (res + f(l, 1, dp, s)) % MOD;
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  string S;
  Solution s;
  while (cin >> S) {
    cout << s.numPermsDISequence(S) << endl;
  }
  return 0;
}
