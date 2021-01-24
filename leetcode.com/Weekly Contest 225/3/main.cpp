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
  int kthLargestValue(vector<vector<int>>& matrix, int k) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> v, d(n);
    d[0] = matrix[0][0];
    v.push_back(d[0]);
    for (int i = 1; i < n; ++i) {
      d[i] = matrix[0][i] ^ d[i - 1];
      v.push_back(d[i]);
    }
    for (int i = 1; i < m; ++i) {
      int cur = matrix[i][0];
      d[0] ^= cur;
      v.push_back(d[0]);
      for (int j = 1; j < n; ++j) {
        cur ^= matrix[i][j];
        d[j] ^= cur;
        v.push_back(d[j]);
      }
    }
    sort(v.rbegin(), v.rend());
    return v[k - 1];
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<int>> A = {{5, 2}, {1, 6}};
  int k = 1;
  cout << s.kthLargestValue(A, k) << endl;
  return 0;
}
