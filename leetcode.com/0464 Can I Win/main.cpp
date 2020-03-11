#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 private:
  int mask, n;
  unordered_map<int, unordered_map<int, bool>> dp;
  bool dfs(int remain, int desiredTotal) {
    auto it_remain = dp.find(remain);
    if (it_remain != dp.end()) {
      auto it_total = it_remain->second.find(desiredTotal);
      if (it_total != it_remain->second.end()) {
        return it_total->second;
      }
    }
    int onebit = 1;
    bool res = false;
    for (int i = 1; i <= n; ++i, onebit <<= 1) {
      if ((remain & onebit) == 0) continue;
      if (desiredTotal - i <= 0 || !dfs(remain ^ onebit, desiredTotal - i)) {
        res = true;
        break;
      }
      if (((mask - (onebit - 1)) & remain) == 0) break;
    }
    return dp[remain][desiredTotal] = res;
  }

 public:
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    n = maxChoosableInteger;
    if ((n + 1) * n / 2 < desiredTotal) return false;
    dp.clear();
    mask = (1 << n) - 1;
    return dfs(mask, desiredTotal);
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int n = 10;
  int t = 11;
  cout << s.canIWin(n, t) << endl;
  return 0;
}
