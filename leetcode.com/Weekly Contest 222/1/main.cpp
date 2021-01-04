#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

class Solution {
 public:
  int maximumUnits(vector<vector<int>>& A, int n) {
    sort(A.begin(), A.end(), [](const vector<int>& a, const vector<int>& b) {
      return a[1] > b[1];
    });
    int i = 0, N = A.size();
    int res = 0;
    while (n && i < N) {
      int x = min(A[i][0], n);
      n -= x;
      res += x * A[i][1];
      if (A[i][0] == x) ++i;
    }
    return res;
  }
};
