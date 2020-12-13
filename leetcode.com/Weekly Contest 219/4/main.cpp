#include <bits/stdc++.h>

#include <vector>

using namespace std;

static int x = []() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

class Solution {
 private:
  int n;
  vector<vector<int>> A;
  int f(int ii, int p, int i, vector<vector<vector<int>>> &dp) {
    if (i == -1) return 0;
    int l = A[p][(ii + 1) % 3], w = A[p][(ii + 2) % 3];
    if (l < w) swap(l, w);
    if (~dp[i][p][ii]) return dp[i][p][ii];
    int res = 0;
    for (int j = 0; j < 3; ++j) {
      int nw = A[i][(j + 1) % 3], nl = A[i][(j + 2) % 3];
      if (nl < nw) swap(nl, nw);
      if (nl <= l && nw <= w && A[i][j] <= A[p][ii]) {
        res = max(res, A[i][j] + f(j, i, i - 1, dp));
      }
    }
    res = max(res, f(ii, p, i - 1, dp));
    return dp[i][p][ii] = res;
  }

 public:
  int maxHeight(vector<vector<int>> &cuboids) {
    n = cuboids.size();
    A = cuboids;
    for (int i = 0; i < n; ++i) {
      sort(A[i].begin(), A[i].end());
    }
    sort(A.begin(), A.end());
    A.push_back({1000, 1000, 1000});
    vector<vector<vector<int>>> dp(
        110, vector<vector<int>>(110, vector<int>(10, -1)));
    return f(0, n, n - 1, dp);
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<vector<int>> A = {{50, 45, 20}, {95, 37, 53}, {45, 23, 12}};
  cout << s.maxHeight(A) << endl;
  return 0;
}

