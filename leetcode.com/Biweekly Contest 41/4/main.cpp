#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

class Solution {
 public:
  int boxDelivering(vector<vector<int>>& boxes, int portsCount, int mb,
                    int mw) {
    int m = boxes.size();
    vector<int> dp(m + 1);

    // sliding window head, window cost, window weight
    int i = 0, cost = 1, w = 0;
    for (int j = 0; j < m; ++j) {
      if (j == 0 || boxes[j][0] != boxes[j - 1][0]) cost += 1;
      w += boxes[j][1];

      while (j - i + 1 > mb || w > mw || (i < j && dp[i + 1] == dp[i])) {
        w -= boxes[i][1];
        if (boxes[i][0] != boxes[i + 1][0]) cost -= 1;
        i++;
      }

      dp[j + 1] = dp[i] + cost;
    }

    return dp[m];
  }
};