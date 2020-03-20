#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// dfs, too slow: 744ms
class Solution {
 private:
  unordered_map<int, unordered_map<int, int>> dp;
  int n;
  int dfs(int idx, int remain, vector<int>& coins) {
    if (remain == 0) return 1;
    if (idx == n) return 0;
    if (dp[idx].count(remain)) return dp[idx][remain];
    int res = 0;
    for (int i = remain / coins[idx]; i >= 0; --i)
      res += dfs(idx + 1, remain - i * coins[idx], coins);
    return dp[idx][remain] = res;
  }

 public:
  int change(int amount, vector<int>& coins) {
    sort(coins.rbegin(), coins.rend());
    n = coins.size();
    dp.clear();
    return dfs(0, amount, coins);
  }
};