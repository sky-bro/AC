#include <iostream>
#include <vector>

using namespace std;

int dr[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dc[] = {-2, -1, 1, 2, -2, -1, 1, 2};

class Solution {
 private:
  vector<vector<vector<double>>> dp;

 public:
  double knightProbability(int N, int K, int r, int c, bool re_init = true) {
    if (re_init) {
      dp.clear();
      dp.resize(N, vector<vector<double>>(N, vector<double>(K + 1, -1)));
    }
    if (K == 0)
      return 1;  // only valid r, c can reach here, so always returns 1
    if (dp[r][c][K] >= 0) return dp[r][c][K];

    double res = 0;
    for (int i = 0; i < 8; ++i) {
      int nr = r + dr[i], nc = c + dc[i];
      if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
        res += .125 * knightProbability(N, K - 1, nr, nc, false);
      }
    }
    return dp[r][c][K] = res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int N, K, r, c;
  while (cin >> N >> K >> r >> c) {
    cout << s.knightProbability(N, K, r, c) << endl;
  }
  return 0;
}
