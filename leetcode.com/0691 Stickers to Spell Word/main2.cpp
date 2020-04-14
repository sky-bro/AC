#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// ref: C++/Java/Python, DP + Memoization with optimization, 29 ms (C++)
// https://leetcode.com/problems/stickers-to-spell-word/discuss/108318/C%2B%2BJavaPython-DP-%2B-Memoization-with-optimization-29-ms-(C%2B%2B)
// nice DFS, fast
class Solution {
 public:
  int minStickers(vector<string>& stickers, string target) {
    int m = stickers.size();
    vector<vector<int>> mp(m, vector<int>(26, 0));
    unordered_map<string, int> dp;
    // count characters a-z for each sticker
    for (int i = 0; i < m; i++)
      for (char c : stickers[i]) mp[i][c - 'a']++;
    dp[""] = 0;
    return helper(dp, mp, target);
  }

 private:
  int helper(unordered_map<string, int>& dp, vector<vector<int>>& mp,
             string target) {
    if (dp.count(target)) return dp[target];
    int ans = INT32_MAX, n = mp.size();
    vector<int> tar(26, 0);
    for (char c : target) tar[c - 'a']++;
    // try every sticker
    for (int i = 0; i < n; i++) {
      // optimization
      // heuristic (this is the key)
      if (mp[i][target[0] - 'a'] == 0) continue;
      string s;
      // apply a sticker on every character a-z
      for (int j = 0; j < 26; j++)
        if (tar[j] - mp[i][j] > 0) s += string(tar[j] - mp[i][j], 'a' + j);
      int tmp = helper(dp, mp, s);
      if (tmp != -1) ans = min(ans, 1 + tmp);
    }
    dp[target] = ans == INT32_MAX ? -1 : ans;
    return dp[target];
  }
};