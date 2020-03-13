#include <iostream>
#include <vector>

using namespace std;

// ref:
// https://leetcode.com/problems/ones-and-zeroes/discuss/95832/C%2B%2B-Clean-and-Short-DP-O(kmn)-Time-O(mn)-Space
class Solution {
 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (string& str : strs) {
      int cur_z = 0, cur_o = 0;
      for (char c : str) {
        c == '0' ? ++cur_z : ++cur_o;
      }
      for (int i = m; i >= cur_z; --i) {
        for (int j = n; j >= cur_o; --j) {
          dp[i][j] = max(dp[i - cur_z][j - cur_o] + 1, dp[i][j]);
        }
      }
    }
    return dp[m][n];
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<string> strs = {"10", "0001", "111001", "1", "0"};
  int m = 5, n = 3;
  cout << s.findMaxForm(strs, m, n) << endl;
  return 0;
}
