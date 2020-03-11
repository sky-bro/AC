#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// ref1: explanation
// https://leetcode.com/problems/can-i-win/discuss/95277/Java-solution-using-HashMap-with-detailed-explanation

// ref2: code
// https://leetcode.com/problems/can-i-win/discuss/95320/Clean-C%2B%2B-beat-98.4-DFS-with-early-termination-check-(detailed-explanation)

/*
For this question, the key part is: what is the state of the game? Intuitively,
to uniquely determine the result of any state, we need to know:
1) The unchosen numbers
2) The remaining desiredTotal to reach
A second thought reveals that 1) and 2) are actually related because we can
always get the 2) by deducting the sum of chosen numbers from original
desiredTotal.
*/
class Solution {
 private:
  int n;
  vector<int8_t> dp;
  bool dfs(int used, int desire) {
    if (~dp[used]) return dp[used];
    for (int i = n; i > 0; --i) {
      if (used & (1 << (i - 1))) continue;
      if (i >= desire || !dfs(used | (1 << (i - 1)), desire - i)) {
        return dp[used] = 1;
      }
    }
    return dp[used] = 0;
  }

 public:
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    n = maxChoosableInteger;
    int sum = (n + 1) * n / 2;
    if (sum < desiredTotal) return false;
    if (sum == desiredTotal) return n & 1;
    dp.resize(1 << n, -1);
    return dfs(0, desiredTotal);
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int n = 10;
  int t = 11;
  cout << s.canIWin(n, t) << endl;
  return 0;
}
