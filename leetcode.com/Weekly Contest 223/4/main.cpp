#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

int sums[1 << 12], dp[1 << 12];
class Solution {
 public:
  int minimumTimeRequired(vector<int>& jobs, int k) {
    int n = jobs.size();
    for (int mask = 1; mask < (1 << n); mask++) {
      for (int i = 0; i < n; i++)
        if (mask & (1 << i)) {
          sums[mask] = dp[mask] = jobs[i] + sums[mask ^ (1 << i)];
          break;
        }
    }
    while (--k) {
      for (int mask = (1 << n) - 1; mask; mask--) {
        int other = mask;
        for (int other = mask; other; other = (other - 1) & mask) {
          dp[mask] = min(dp[mask], max(dp[mask ^ other], sums[other]));
        }
      }
    }
    return dp[(1 << n) - 1];
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> A = {1, 2, 4, 7, 8};
  int k = 2;
  // A = {5, 15, 4, 9, 15, 8, 8, 9};
  // k = 2;
  cout << s.minimumTimeRequired(A, k) << endl;
  return 0;
}
