#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1e9 + 7;

class Solution {
 private:
  int n;
  long long dfs(int i, const string& s, vector<long long>& dp) {
    if (~dp[i]) return dp[i];
    if (s[i] == '0') {
      return dp[i] = 0;
    }
    // i always less than n-1 (s[i+1] is valid)
    // 1 digit
    long long res = (s[i] == '*' ? 9 : 1) * dfs(i + 1, s, dp) % MOD;
    // 2 digits
    if (s[i] == '1' || s[i] == '*') {
      res += (s[i + 1] == '*' ? 9 : 1) * dfs(i + 2, s, dp);
      res %= MOD;
    }
    if (s[i] == '2' || s[i] == '*') {
      if (s[i + 1] == '*') {
        res += 6 * dfs(i + 2, s, dp);
        res %= MOD;
      } else if (s[i + 1] <= '6') {
        res += dfs(i + 2, s, dp);
        res %= MOD;
      }
    }
    return dp[i] = res;
  }

 public:
  int numDecodings(string s) {
    n = s.length();
    vector<long long> dp(n + 1, -1);
    dp[n] = 1;
    dp[n - 1] = s[n - 1] == '*' ? 9 : (s[n-1] != '0');
    return dfs(0, s, dp);
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  string str = "*1*1*0"; // 404
  while (cin >> str) {
    cout << s.numDecodings(str) << endl;
  }
  return 0;
}
