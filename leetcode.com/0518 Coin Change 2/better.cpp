#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// dfs, too slow: 744ms
class Solution {
 public:
  int change(int t, vector<int>& cs) {
    // int dp[t + 1] = {1};
    vector<int> dp(t + 1);
    dp[0] = 1;
    for (auto c : cs)
      for (auto j = c; j <= t; ++j) dp[j] += dp[j - c];
    return dp[t];
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> cs = {2, 1};
  int t = 4;
  cout << s.change(t, cs) << endl;
  return 0;
}
