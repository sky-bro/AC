#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// ref: Rewrite of contest winner's solution
// https://leetcode.com/problems/stickers-to-spell-word/discuss/108333/Rewrite-of-contest-winner's-solution
// standard DP solution, start from here
class Solution {
 public:
  int minStickers(vector<string>& stickers, string target) {
    int n = target.size(), N = 1 << n;
    vector<uint> dp(N, -1);
    dp[0] = 0;
    for (int i = 0; i < N; i++)
      if (dp[i] != -1) {
        for (string& s : stickers) {
          int now = i;
          for (char c : s) {
            for (int r = 0; r < n; r++) {
              if (target[r] == c && !((now >> r) & 1)) {
                now |= 1 << r;
                break;
              }
            }
          }
          dp[now] = min(dp[now], dp[i] + 1);
        }
      }
    return dp[N - 1];
  }
};