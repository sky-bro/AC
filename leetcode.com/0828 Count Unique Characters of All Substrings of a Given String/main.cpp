#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

class Solution {
 public:
  int uniqueLetterString(string s) {
    long long res = 0;
    vector<vector<int>> dp(26);
    int n = s.size();
    int pre = 0;
    for (int i = 0; i < n; ++i) {
      int idx = s[i] - 'A';
      dp[idx].push_back(i);
      if (dp[idx].size() == 1) {
        res = (res + (pre += 1)) % MOD;
      } else if (dp[idx].size() == 2) {
        res = (res + (pre -= 1)) % MOD;
      } else {
        res = (res + pre) % MOD;
      }
    }

    for (auto &vi : dp) {
      reverse(vi.begin(), vi.end());
    }

    pre = res;
    for (int i = 0; i < n; ++i) {
      int idx = s[i] - 'A';
      dp[idx].pop_back();
      switch (dp[idx].size()) {
        case 0:
          // A...
          res = (res + (pre -= n - i)) % MOD;
          break;
        case 1:
          // A...A...
          res = (res + (pre -= (dp[idx].back() - i) - (n - dp[idx].back()))) %
                MOD;
          break;
        default:
          // A...A...A...
          int next_next_i = dp[idx][dp[idx].size() - 2];
          res = (res + (pre -= (dp[idx].back() - i) -
                               (next_next_i - dp[idx].back()))) %
                MOD;
          break;
      }
    }
    return (res + MOD) % MOD;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;

  string str = "ABA";  // 6
  str = "ABC";         // 10
  str = "LEETCODE";    // 92
  while (cin >> str) {
    cout << s.uniqueLetterString(str) << endl;
  }
  return 0;
}
