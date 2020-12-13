#include<bits/stdc++.h>
#include <vector>

using namespace std;

static int x = []() {ios::sync_with_stdio(false); cin.tie(0); return 0; } ();
typedef long long ll;

class Solution {
  private:
    int n;
    vector<int> sums;
    int f(int l, int r, vector<vector<int>> &dp) {
      if (l == r) return 0;
      if (dp[l][r] != INT32_MAX) return dp[l][r];
      int res = max(sums[r] - sums[l] - f(l+1, r, dp), sums[r-1]-(l?sums[l-1]:0)-f(l, r-1, dp));
      return dp[l][r] = res;
    }
public:
    int stoneGameVII(vector<int>& stones) {
        n = stones.size();
        sums.clear();
        sums.resize(n);
        sums[0] = stones[0];
        for (int i = 1; i < n; ++i) {
          sums[i] = sums[i-1] + stones[i];
        }
        vector<vector<int>> dp(n, vector<int>(n, INT32_MAX));
        return f(0, n-1, dp);
    }
};
