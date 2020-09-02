#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  double champagneTower(int poured, int query_row, int query_glass) {
    vector<double> dp(102);
    dp[0] = poured;
    for (int r = 1; r <= query_row; ++r) {
      for (int c = r; c >= 0; --c) {
        dp[c + 1] += dp[c] = max(0.0, (dp[c] - 1) / 2);
      }
    }
    return min(dp[query_glass], 1.0);
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int poured = 40, r = 8, c = 2;  // 0.59375
  cout << s.champagneTower(poured, r, c) << endl;
  while (cin >> poured >> r >> c)
    cout << s.champagneTower(poured, r, c) << endl;
  return 0;
}
