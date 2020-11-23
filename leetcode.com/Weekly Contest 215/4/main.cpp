#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int dp[5][5][7][7][250];

class Solution {
 private:
  int M, N;
  inline int get_r(vector<int>& row) {
    int r = 0;
    for (int x : row) {
      r = r * 3 + x;
    }
    return r;
  }

  void update_row(vector<int>& row, int start, int end, int x) {
    int d = start < end ? 1 : -1;
    for (; start != end; start += d) {
      row[start] = row[start + d];
    }
    row[end] = x;
  }

  int dfs(int idx, vector<int>& row, int a, int b,
          int s) {  // a: 1, b: 2, s: 0
    if (idx == M * N) return 0;
    int r = get_r(row);
    int i = idx / N, j = idx % N;
    if (~dp[i][j][a][b][r]) {
      return dp[i][j][a][b][r];
    }
    int& res = dp[i][j][a][b][r];
    int bak = row[N - 1];
    // if (s > 0) {
    if (true) {  // space
      update_row(row, N - 1, 0, 0);
      int cur = dfs(idx + 1, row, a, b, s - 1);
      update_row(row, 0, N - 1, bak);
      res = max(res, cur);
    }
    if (a > 0) {
      int cur = 120;
      if (j != 0) {  // left
        if (row[0] == 1) {
          cur -= 60;
        } else if (row[0] == 2) {
          cur -= 10;
        }
      }
      // top
      if (row[N - 1] == 1) {
        cur -= 60;
      } else if (row[N - 1] == 2) {
        cur -= 10;
      }
      update_row(row, N - 1, 0, 1);
      cur += dfs(idx + 1, row, a - 1, b, s);
      update_row(row, 0, N - 1, bak);
      res = max(res, cur);
    }
    if (b > 0) {
      int cur = 40;
      if (j != 0) {  // left
        if (row[0] == 1) {
          cur -= 10;
        } else if (row[0] == 2) {
          cur += 40;
        }
      }
      // top
      if (row[N - 1] == 1) {
        cur -= 10;
      } else if (row[N - 1] == 2) {
        cur += 40;
      }
      update_row(row, N - 1, 0, 2);
      cur += dfs(idx + 1, row, a, b - 1, s);
      update_row(row, 0, N - 1, bak);
      res = max(res, cur);
    }

    return res;
  }

 public:
  int getMaxGridHappiness(int m, int n, int introvertsCount,
                          int extrovertsCount) {
    memset(dp, -1, sizeof(dp));
    M = m, N = n;
    int space = m * n - introvertsCount - extrovertsCount;
    vector<int> row(n, 0);
    return dfs(0, row, introvertsCount, extrovertsCount, space);
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  int m = 3, n = 1, i = 2, e = 1;
  m = 3, n = 4, i = 6, e = 5;
  cout << s.getMaxGridHappiness(m, n, i, e) << endl;
  return 0;
}
