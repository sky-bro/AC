#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// ref: Summary of the BFS and DP solutions with intuitive explanation
// https://leetcode.com/problems/race-car/discuss/124326/Summary-of-the-BFS-and-DP-solutions-with-intuitive-explanation

class Solution {
 private:
  vector<int> dp;
  int f(int i) {
    if (~dp[i]) return dp[i];
    int j = 1;  // from i to j
    int m = 1;  // take m steps
    dp[i] = INT32_MAX;
    // case 1: i > j
    // go right then go left then right: -> <- ->
    for (; j < i; j = (1 << ++m) - 1) {
      for (int m2 = 0, j2 = 0; j2 < j; j2 = (1 << ++m2) - 1) {
        dp[i] = min(dp[i], m + 1 + m2 + 1 + f(i - (j - j2)));
      }
    }

    // case 2: i == j
    if (i == j) {
      dp[i] = min(dp[i], m);
    }
    // case 3: i < j
    else {
      dp[i] = min(dp[i], m + 1 + f(j - i));
    }
    return dp[i];
  }

 public:
  int racecar(int target) {
    dp.clear();
    dp.resize(target + 1, -1);
    return f(target);
  }
};
