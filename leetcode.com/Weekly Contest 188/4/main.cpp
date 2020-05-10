#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

class Solution {
private:
  int m, n;
  long long dfs(vector<string> &pizza, vector<vector<vector<vector<int>>>> &dp, vector<vector<vector<vector<vector<int>>>>> &dp2, int r, int rb, int c, int cb, int k) {
    if (~dp2[r][rb][c][cb][k]) return dp2[r][rb][c][cb][k];
    if (k == 1) return 1;
    long long res = 0;
    for (int i = r; i < rb; ++i) {
      if (dp[r][i][c][cb] && dp[i+1][rb][c][cb] / (k-1)) {
        res += dfs(pizza, dp, dp2, i+1, rb, c, cb, k-1);
        res %= MOD;
      }
    }
    for (int j = c; j < cb; ++j) {
      if (dp[r][rb][c][j] && dp[r][rb][j+1][cb] / (k-1)) {
        res += dfs(pizza, dp, dp2, r, rb, j+1, cb, k-1);
        res %= MOD;
      }
    }
    return dp2[r][rb][c][cb][k] = res;
  }
public:
    int ways(vector<string>& pizza, int k) {
      m = pizza.size(), n = pizza[0].size();
      vector<vector<vector<vector<int>>>> dp(m, vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(n))));
      vector<vector<vector<vector<vector<int>>>>> dp2(m, vector<vector<vector<vector<int>>>>(m, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(k+1, -1)))));
      for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
          dp[r][r][c][c] = pizza[r][c] == 'A';
          for (int cd = 1; c + cd < n; ++cd) {
            dp[r][r][c][c+cd] = dp[r][r][c][c+cd-1] + (pizza[r][c+cd] == 'A');
          }
        }
        for (int rd = 1; r + rd < m; ++rd) {
          for (int c = 0; c < n; ++c) {
            dp[r][r+rd][c][c] = dp[r][r+rd-1][c][c] + (pizza[r+rd][c] == 'A');
            for (int cd = 1; c + cd < n; ++cd) {
              dp[r][r+rd][c][c+cd] = dp[r][r+rd][c][c+cd-1] + dp[r][r+rd-1][c+cd][c+cd] + (pizza[r+rd][c+cd] == 'A');
            }
          }
        }
      }
      if (dp[0][m-1][0][n-1] / k == 0) return 0;
      return dfs(pizza,dp, dp2, 0, m-1, 0, n-1, k);
    }
};

int main(int argc, char const *argv[])
{
  Solution s;
  vector<string> pizza = {"..A.A.AAA...AAAAAA.AA..A..A.A......A.AAA.AAAAAA.AA","A.AA.A.....AA..AA.AA.A....AAA.A........AAAAA.A.AA.","A..AA.AAA..AAAAAAAA..AA...A..A...A..AAA...AAAA..AA","....A.A.AA.AA.AA...A.AA.AAA...A....AA.......A..AA.","AAA....AA.A.A.AAA...A..A....A..AAAA...A.A.A.AAAA..","....AA..A.AA..A.A...A.A..AAAA..AAAA.A.AA..AAA...AA","A..A.AA.AA.A.A.AA..A.A..A.A.AAA....AAAAA.A.AA..A.A",".AA.A...AAAAA.A..A....A...A.AAAA.AA..A.AA.AAAA.AA.","A.AA.AAAA.....AA..AAA..AAAAAAA...AA.A..A.AAAAA.A..","A.A...A.A...A..A...A.AAAA.A..A....A..AA.AAA.AA.AA.",".A.A.A....AAA..AAA...A.AA..AAAAAAA.....AA....A....","..AAAAAA..A..A...AA.A..A.AA......A.AA....A.A.AAAA.","...A.AA.AAA.AA....A..AAAA...A..AAA.AAAA.A.....AA.A","A.AAAAA..A...AAAAAAAA.AAA.....A.AAA.AA.A..A.A.A...","A.A.AA...A.A.AA...A.AA.AA....AA...AA.A..A.AA....AA","AA.A..A.AA..AAAAA...A..AAAAA.AA..AA.AA.A..AAAAA..A","...AA....AAAA.A...AA....AAAAA.A.AAAA.A.AA..AA..AAA","..AAAA..AA..A.AA.A.A.AA...A...AAAAAAA..A.AAA..AA.A","AA....AA....AA.A......AAA...A...A.AA.A.AA.A.A.AA.A","A.AAAA..AA..A..AAA.AAA.A....AAA.....A..A.AA.A.A...","..AA...AAAAA.A.A......AA...A..AAA.AA..A.A.A.AA..A.",".......AA..AA.AAA.A....A...A.AA..A.A..AAAAAAA.AA.A",".A.AAA.AA..A.A.A.A.A.AA...AAAA.A.A.AA..A...A.AAA..","A..AAAAA.A..A..A.A..AA..A...AAA.AA.A.A.AAA..A.AA..","A.AAA.A.AAAAA....AA..A.AAA.A..AA...AA..A.A.A.AA.AA",".A..AAAA.A.A.A.A.......AAAA.AA...AA..AAA..A...A.AA","A.A.A.A..A...AA..A.AAA..AAAAA.AA.A.A.A..AA.A.A....","A..A..A.A.AA.A....A...A......A.AA.AAA..A.AA...AA..",".....A..A...A.A...A..A.AA.A...AA..AAA...AA..A.AAA.","A...AA..A..AA.A.A.AAA..AA..AAA...AAA..AAA.AAAAA...","AA...AAA.AAA...AAAA..A...A..A...AA...A..AA.A...A..","A.AA..AAAA.AA.AAA.A.AA.A..AAAAA.A...A.A...A.AA....","A.......AA....AA..AAA.AAAAAAA.A.AA..A.A.AA....AA..",".A.A...AA..AA...AA.AAAA.....A..A..A.AA.A.AA...A.AA","..AA.AA.AA..A...AA.AA.AAAAAA.....A.AA..AA......A..","AAA..AA...A....A....AA.AA.AA.A.A.A..AA.AA..AAA.AAA","..AAA.AAA.A.AA.....AAA.A.AA.AAAAA..AA..AA.........",".AA..A......A.A.AAA.AAAA...A.AAAA...AAA.AAAA.....A","AAAAAAA.AA..A....AAAA.A..AA.A....AA.A...A.A....A..",".A.A.AA..A.AA.....A.A...A.A..A...AAA..A..AA..A.AAA","AAAA....A...A.AA..AAA..A.AAA..AA.........AA.AAA.A.","......AAAA..A.AAA.A..AAA...AAAAA...A.AA..A.A.AA.A.","AA......A.AAAAAAAA..A.AAA...A.A....A.AAA.AA.A.AAA.",".A.A....A.AAA..A..AA........A.AAAA.AAA.AA....A..AA",".AA.A...AA.AAA.A....A.A...A........A.AAA......A...","..AAA....A.A...A.AA..AAA.AAAAA....AAAAA..AA.AAAA..","..A.AAA.AA..A.AA.A...A.AA....AAA.A.....AAA...A...A",".AA.AA...A....A.AA.A..A..AAA.A.A.AA.......A.A...A.","...A...A.AA.A..AAAAA...AA..A.A..AAA.AA...AA...A.A.","..AAA..A.A..A..A..AA..AA...A..AA.AAAAA.A....A..A.A"};
  int k = 8;
  // pizza = {".A..A","A.A..","A.AA.","AAAA.","A.AA."};
  // k = 5;
  // pizza = {"A.AA.","AAAA.","A.AA."};
  // k = 4;
  cout<<s.ways(pizza, k)<<endl;
  return 0;
}
