#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

class Solution {
  int n, j;
  int dfs(vector<int>& locations, vector<vector<long long>>& dp, int i, int f) {
    if (~dp[i][f]) return dp[i][f];
    if (abs(locations[i] - locations[j]) > f) return dp[i][f] = 0;
    int res = 0;
    if (i == j) ++res;
    for (int k = 0; k < n; ++k) {
      if (k == i) continue;
      int nf = f - abs(locations[i] - locations[k]);
      if (nf < 0) continue;
      res = (res + dfs(locations, dp, k, nf)) % MOD;
    }
    return dp[i][f] = res;
  }

 public:
  int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    n = locations.size();
    j = finish;
    vector<vector<long long>> dp(n, vector<long long>(201, -1));
    return dfs(locations, dp, start, fuel);
  }
};

int main(int argc, char const* argv[]) {
  vector<int> locations = {2, 3, 6, 8, 4};
  int i = 1, j = 3, f = 5;
  Solution s;
  cout << s.countRoutes(locations, i, j, f) << endl;
  return 0;
}
