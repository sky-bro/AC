#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int matrixScore(vector<vector<int>>& A) {
    int m = A.size(), n = A[0].size();
    int mask = (1 << n) - 1;
    bool is_one[m];
    for (int i = 0; i < m; ++i) {
      if (A[i][0])
        is_one[i] = true;
      else
        is_one[i] = false;
    }
    for (int j = 1; j < n; ++j) {
      int gain = 0;
      for (int i = 0; i < m; ++i) {
        if (is_one[i]) {
          gain += A[i][j] == 0 ? 1 : -1;
        } else {
          gain += A[i][j] == 0 ? -1 : 1;
        }
      }
      if (gain > 0) {
        for (int i = 0; i < m; ++i) {
          A[i][j] ^= 1;
        }
      }
    }
    int res = 0;
    for (int i = 0; i < m; ++i) {
      int cur = 0;
      for (int j = 0; j < n; ++j) {
        cur = cur * 2 + A[i][j];
      }
      if (is_one[i]) {
        res += cur;
      } else {
        res += mask - cur;
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<int>> A = {{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}};
  cout << s.matrixScore(A) << endl;
  return 0;
}
