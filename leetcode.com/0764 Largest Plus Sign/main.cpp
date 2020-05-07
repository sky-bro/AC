#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> grid(N, vector<int>(N, 1));
        for (auto &mine: mines) {
          grid[mine[0]][mine[1]] = 0;
        }
        vector<vector<int>> dp(N, vector<int>(N)); // up, down
        vector<vector<int>> dp2(N, vector<int>(N)); // left
        vector<vector<int>> dp3(N, vector<int>(N)); // right
        int res = 0;
        // up, left
        for (int i = 0; i < N; ++i) {
          if (grid[0][i]) {
            dp[0][i] = 1;
            res = 1;
          }
        }
        for (int i = 1; i < N; ++i) {
          int cnt = 0;
          for (int j = 0; j < N; ++j) {
            if (grid[i][j]) { // 1
              dp[i][j] = dp[i-1][j]+1;
              dp2[i][j] = ++cnt;
            } else {
              cnt = 0;
            }
          }
        }
        // down, right
        for (int i = N-1; i >= 0; --i) {
          if (grid[N-1][i]) {
            dp3[N-1][i] = 1;
            res = 1;
          }
        }
        for (int i = N-2; i >= 0; --i) {
          int cnt = 0;
          for (int j = N-1; j >= 0; --j) {
            if (grid[i][j]) { // 1
              int cur1 = min(dp3[i][j] = dp3[i+1][j]+1, ++cnt);
              int cur2 = min(dp[i][j], dp2[i][j]);
              int cur = min(cur1, cur2);
              res = max(res, cur);
            } else {
              cnt = 0;
            }
          }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
  int N = 5;
  vector<vector<int>> mines = {{4,2}}; // 2
  mines = {{0,1},{0,2},{1,0},{1,2},{1,4},{2,0},{2,2},{3,0},{3,1},{4,0},{4,1},{4,3},{4,4}}; // 1
  Solution s;
  cout<<s.orderOfLargestPlusSign(N, mines)<<endl;
  return 0;
}
