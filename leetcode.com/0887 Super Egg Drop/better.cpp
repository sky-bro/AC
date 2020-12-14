#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  // 2D
  // int superEggDrop(int K, int N) {
  //   vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
  //   int m = 0;
  //   while (dp[m][K] < N) {
  //     m++;
  //     for (int k = 1; k <= K; ++k)
  //       dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1;
  //   }
  //   return m;
  // }

  // 1D
  int superEggDrop(int K, int N) {
    vector<int> dp(K + 1, 0);
    int m;
    for (m = 0; dp[K] < N; m++)
      for (int k = K; k > 0; --k)
        dp[k] += dp[k - 1] + 1;
    return m;
  }
};

int main() {
  Solution s;
  int K, N;
  while (cin >> K >> N) {
    cout << s.superEggDrop(K, N) << endl;
  }
}
