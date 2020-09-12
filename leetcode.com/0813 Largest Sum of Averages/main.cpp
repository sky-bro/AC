#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int n;
  double f(vector<vector<double>>& dp, vector<int>& A, int K, int I) {
    if (dp[K][I] > 0) return dp[K][I];
    int len = 1;
    double s = 0;
    double res = 0;
    for (int i = I; i + K <= n; ++len) {
      s += A[i++];
      res = max(res, s / len + f(dp, A, K - 1, i));
    }
    return dp[K][I] = res;
  }

 public:
  double largestSumOfAverages(vector<int>& A, int K) {
    n = A.size();
    vector<vector<double>> dp(K + 1, vector<double>(n, 0));
    double s = 0;
    for (int i = n - 1; i >= 0; --i) {
      s += A[i];
      dp[1][i] = s / (n - i);
    }
    return f(dp, A, K, 0);
  }
};

int main(int argc, char const* argv[]) {
  vector<int> A = {9, 1, 2, 3, 9};
  int K = 3;
  A = {4663, 3020, 7789, 1627, 9668, 1356, 4207, 1133, 8765, 4649,
       205,  6455, 8864, 3554, 3916, 5925, 3995, 4540, 3487, 5444,
       8259, 8802, 6777, 7306, 989,  4958, 2921, 8155, 4922, 2469,
       6923, 776,  9777, 1796, 708,  786,  3158, 7369, 8715, 2136,
       2510, 3739, 6411, 7996, 6211, 8282, 4805, 236,  1489, 7698};
  K = 27;
  Solution s;
  cout << s.largestSumOfAverages(A, K) << endl;  // 20
  return 0;
}
