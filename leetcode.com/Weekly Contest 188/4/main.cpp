#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
typedef long long ll;

class Solution {
 private:
  ll dfs(vector<string>& pizza, int k, vector<vector<int>>& dp,
         vector<vector<vector<int>>>& dp2, int m, int n) {
    if (~dp2[m][n][k]) return dp2[m][n][k];
    if (k == 1) return dp2[m][n][k] = 1;
    ll res = 0;
    for (int i = 1; i < m; ++i) {
      if (dp[m][n] - dp[i][n] && dp[i][n] / (k - 1))
        res += dfs(pizza, k - 1, dp, dp2, i, n);
    }
    for (int i = 1; i < n; ++i) {
      if (dp[m][n] - dp[m][i] && dp[m][i] / (k - 1))
        res += dfs(pizza, k - 1, dp, dp2, m, i);
    }
    return dp2[m][n][k] = res % MOD;
  }

 public:
  int ways(vector<string>& pizza, int k) {
    int m = pizza.size(), n = pizza[0].size();
    reverse(pizza.begin(), pizza.end());
    for (auto& row : pizza) reverse(row.begin(), row.end());
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    vector<vector<vector<int>>> dp2(
        m + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, -1)));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        dp[i + 1][j + 1] =
            dp[i][j + 1] + dp[i + 1][j] - dp[i][j] + (pizza[i][j] == 'A');
      }
    }
    if (dp[m][n] / k == 0) return 0;
    return dfs(pizza, k, dp, dp2, m, n);
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<string> pizza = {"..A.A.AAA...AAAAAA.AA..A..A.A......A.AAA.AAAAAA.AA",
                          "A.AA.A.....AA..AA.AA.A....AAA.A........AAAAA.A.AA.",
                          "A..AA.AAA..AAAAAAAA..AA...A..A...A..AAA...AAAA..AA",
                          "....A.A.AA.AA.AA...A.AA.AAA...A....AA.......A..AA.",
                          "AAA....AA.A.A.AAA...A..A....A..AAAA...A.A.A.AAAA..",
                          "....AA..A.AA..A.A...A.A..AAAA..AAAA.A.AA..AAA...AA",
                          "A..A.AA.AA.A.A.AA..A.A..A.A.AAA....AAAAA.A.AA..A.A",
                          ".AA.A...AAAAA.A..A....A...A.AAAA.AA..A.AA.AAAA.AA.",
                          "A.AA.AAAA.....AA..AAA..AAAAAAA...AA.A..A.AAAAA.A..",
                          "A.A...A.A...A..A...A.AAAA.A..A....A..AA.AAA.AA.AA.",
                          ".A.A.A....AAA..AAA...A.AA..AAAAAAA.....AA....A....",
                          "..AAAAAA..A..A...AA.A..A.AA......A.AA....A.A.AAAA.",
                          "...A.AA.AAA.AA....A..AAAA...A..AAA.AAAA.A.....AA.A",
                          "A.AAAAA..A...AAAAAAAA.AAA.....A.AAA.AA.A..A.A.A...",
                          "A.A.AA...A.A.AA...A.AA.AA....AA...AA.A..A.AA....AA",
                          "AA.A..A.AA..AAAAA...A..AAAAA.AA..AA.AA.A..AAAAA..A",
                          "...AA....AAAA.A...AA....AAAAA.A.AAAA.A.AA..AA..AAA",
                          "..AAAA..AA..A.AA.A.A.AA...A...AAAAAAA..A.AAA..AA.A",
                          "AA....AA....AA.A......AAA...A...A.AA.A.AA.A.A.AA.A",
                          "A.AAAA..AA..A..AAA.AAA.A....AAA.....A..A.AA.A.A...",
                          "..AA...AAAAA.A.A......AA...A..AAA.AA..A.A.A.AA..A.",
                          ".......AA..AA.AAA.A....A...A.AA..A.A..AAAAAAA.AA.A",
                          ".A.AAA.AA..A.A.A.A.A.AA...AAAA.A.A.AA..A...A.AAA..",
                          "A..AAAAA.A..A..A.A..AA..A...AAA.AA.A.A.AAA..A.AA..",
                          "A.AAA.A.AAAAA....AA..A.AAA.A..AA...AA..A.A.A.AA.AA",
                          ".A..AAAA.A.A.A.A.......AAAA.AA...AA..AAA..A...A.AA",
                          "A.A.A.A..A...AA..A.AAA..AAAAA.AA.A.A.A..AA.A.A....",
                          "A..A..A.A.AA.A....A...A......A.AA.AAA..A.AA...AA..",
                          ".....A..A...A.A...A..A.AA.A...AA..AAA...AA..A.AAA.",
                          "A...AA..A..AA.A.A.AAA..AA..AAA...AAA..AAA.AAAAA...",
                          "AA...AAA.AAA...AAAA..A...A..A...AA...A..AA.A...A..",
                          "A.AA..AAAA.AA.AAA.A.AA.A..AAAAA.A...A.A...A.AA....",
                          "A.......AA....AA..AAA.AAAAAAA.A.AA..A.A.AA....AA..",
                          ".A.A...AA..AA...AA.AAAA.....A..A..A.AA.A.AA...A.AA",
                          "..AA.AA.AA..A...AA.AA.AAAAAA.....A.AA..AA......A..",
                          "AAA..AA...A....A....AA.AA.AA.A.A.A..AA.AA..AAA.AAA",
                          "..AAA.AAA.A.AA.....AAA.A.AA.AAAAA..AA..AA.........",
                          ".AA..A......A.A.AAA.AAAA...A.AAAA...AAA.AAAA.....A",
                          "AAAAAAA.AA..A....AAAA.A..AA.A....AA.A...A.A....A..",
                          ".A.A.AA..A.AA.....A.A...A.A..A...AAA..A..AA..A.AAA",
                          "AAAA....A...A.AA..AAA..A.AAA..AA.........AA.AAA.A.",
                          "......AAAA..A.AAA.A..AAA...AAAAA...A.AA..A.A.AA.A.",
                          "AA......A.AAAAAAAA..A.AAA...A.A....A.AAA.AA.A.AAA.",
                          ".A.A....A.AAA..A..AA........A.AAAA.AAA.AA....A..AA",
                          ".AA.A...AA.AAA.A....A.A...A........A.AAA......A...",
                          "..AAA....A.A...A.AA..AAA.AAAAA....AAAAA..AA.AAAA..",
                          "..A.AAA.AA..A.AA.A...A.AA....AAA.A.....AAA...A...A",
                          ".AA.AA...A....A.AA.A..A..AAA.A.A.AA.......A.A...A.",
                          "...A...A.AA.A..AAAAA...AA..A.A..AAA.AA...AA...A.A.",
                          "..AAA..A.A..A..A..AA..AA...A..AA.AAAAA.A....A..A.A"};
  int k = 8;
  // pizza = {".A..A","A.A..","A.AA.","AAAA.","A.AA."};
  // k = 5;
  // pizza = {"A.AA.","AAAA.","A.AA."};
  // k = 4;
  cout << s.ways(pizza, k) << endl;
  return 0;
}
