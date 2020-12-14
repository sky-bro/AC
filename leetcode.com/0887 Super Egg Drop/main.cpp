#include <iostream>
#include <vector>

using namespace std;

int dp[110][10010];
// TLE
class Solution {
private:
  int f(int k, int n) {
    if (k == 1)
      return n;
    if (n <= 2)
      return n;
    if (dp[k][n])
      return dp[k][n];
    int res = max(f(k - 1, (n - 1) / 2), f(k, n / 2)) + 1;
    int r = n / 2 + 1;
    while (r < n) {
      int cur = max(f(k - 1, (n - r - 1)), f(k, r)) + 1;
      if (cur > res)
        break;
      res = cur;
      ++r;
    }
    return dp[k][n] = res;
  }

public:
  int superEggDrop(int K, int N) { return f(K, N); }
};

int main() {
  Solution s;
  int K, N;
  while (cin >> K >> N) {
    cout << s.superEggDrop(K, N) << endl;
  }
}
