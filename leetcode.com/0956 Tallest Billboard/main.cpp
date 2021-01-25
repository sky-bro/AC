#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

// ref: Java knapsack O(N*sum)
// https://leetcode.com/problems/tallest-billboard/discuss/203261/Java-knapsack-O(N*sum)
// class Solution {
//  public:
//   int tallestBillboard(vector<int>& rods) {
//     int n = rods.size();
//     unordered_map<int, int> dp;
//     dp[0] = 0;
//     for (int x : rods) {
//       unordered_map<int, int> cur;
//       for (auto& p : dp) {
//         cur[p.first - x] = max(p.second, cur[p.first - x]);
//         cur[p.first] = max(p.second, cur[p.first]);
//         cur[p.first + x] = max(p.second + x, cur[p.first + x]);
//       }
//       dp = cur;
//     }
//     return dp[0];
//   }
// };

class Solution {
 public:
  int tallestBillboard(vector<int>& rods) {
    int n = rods.size();
    int sum = accumulate(rods.begin(), rods.end(), 0);
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
    vector<vector<bool>> vis(n + 1, vector<bool>(sum + 1));
    vis[0][sum / 2] = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= sum; ++j) {
        if (j - rods[i] >= 0 && vis[i][j - rods[i]]) {
          vis[i + 1][j] = true;
          dp[i + 1][j] = max(dp[i][j - rods[i]] /*  + rods[i] */, dp[i + 1][j]);
        }
        if (vis[i][j]) {
          vis[i + 1][j] = true;
          dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
        }
        if (j + rods[i] <= sum && vis[i][j + rods[i]]) {
          vis[i + 1][j] = true;
          dp[i + 1][j] = max(dp[i][j + rods[i]] + rods[i], dp[i + 1][j]);
        }
      }
    }
    return dp[n][sum / 2];
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> rods = {1, 2, 3, 6};
  cout << s.tallestBillboard(rods) << endl;
  return 0;
}
