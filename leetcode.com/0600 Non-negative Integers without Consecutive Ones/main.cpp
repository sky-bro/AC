#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int n;
  // i:
  // 0: set cur bit 0, number building is not smaller
  // 1: set cur bit 1, number building is not smaller
  // 2: set cur bit 0, number building is smaller
  // 3: set cur bit 1, number building is smaller
  int dfs(vector<vector<int>> &dp, int i, int j) {
    if (~dp[i][j]) return dp[i][j];
    // test if cur_bit is zero
    bool is_zero = ((1 << j) & n) == 0;
    int res;
    if (is_zero) {
      switch (i) {
        case 0:
          res = dfs(dp, 0, j - 1) + dfs(dp, 1, j - 1);
          break;
        case 1:
          res = 0;
          break;
        case 2:
          res = dfs(dp, 2, j - 1) + dfs(dp, 3, j - 1);
          break;
        case 3:
          res = dfs(dp, 2, j - 1);  // no consecutive ones
      }
    } else {
      switch (i) {
        case 0:
          res = dfs(dp, 2, j - 1) + dfs(dp, 3, j - 1);  // get smaller
          break;
        case 1:
          res = dfs(dp, 0, j - 1);  // no consecutive ones
          break;
        case 2:
          res = dfs(dp, 2, j - 1) + dfs(dp, 3, j - 1);
          break;
        case 3:
          res = dfs(dp, 2, j - 1);  // no consecutive ones
      }
    }
    return dp[i][j] = res;
  }

 public:
  int findIntegers(int num) {
    n = num;
    vector<vector<int>> dp(4, vector<int>(32, -1));
    dp[1][0] = num & 1;
    dp[0][0] = dp[2][0] = dp[3][0] = 1;
    return dfs(dp, 0, 30) + dfs(dp, 1, 30);
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int num;
  while (cin >> num) {
    cout << s.findIntegers(num) << endl;
  }
  return 0;
}
