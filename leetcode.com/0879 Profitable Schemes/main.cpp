#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

typedef long long ll;

ll d[110][110][110];

class Solution {
 private:
  int N;

 public:
  int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
    N = group.size();
    memset(d, 0, sizeof(d));
    for (int g = 0; g <= G; ++g) {
      d[0][g][0] = (g < group[0]) ? 1 : 2;
    }
    for (int n = 1; n < N; ++n) {
      for (int g = 0; g <= G; ++g) {
        int ng = g - group[n];
        if (ng >= 0) d[n][g][0] = d[n - 1][ng][0];
        d[n][g][0] = (d[n][g][0] + d[n - 1][g][0]) % MOD;
      }
    }
    for (int g = 0; g <= G; ++g) {
      for (int p = 1; p <= P; ++p) {
        if (g >= group[0]) {
          d[0][g][p] = p <= profit[0];
        } else {
          d[0][g][p] = 0;
        }
      }
    }
    for (int n = 1; n < N; ++n) {
      for (int g = 0; g <= G; ++g) {
        for (int p = 1; p <= P; ++p) {
          int ng = g - group[n];
          int np = p - profit[n];
          if (ng >= 0) {
            if (np > 0) {
              d[n][g][p] = d[n - 1][ng][np];
            } else {
              d[n][g][p] = d[n - 1][ng][0];  // d2[n-1][ng]
            }
          }
          d[n][g][p] = (d[n][g][p] + d[n - 1][g][p]) % MOD;
        }
      }
    }
    return d[N - 1][G][P];
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  int G = 100, P = 100;
  vector<int> group = {
      2,  5,  36, 2,  5,  5,  14, 1,  12, 1,  14, 15, 1,  1,  27, 13, 6,
      59, 6,  1,  7,  1,  2,  7,  6,  1,  6,  1,  3,  1,  2,  11, 3,  39,
      21, 20, 1,  27, 26, 22, 11, 17, 3,  2,  4,  5,  6,  18, 4,  14, 1,
      1,  1,  3,  12, 9,  7,  3,  16, 5,  1,  19, 4,  8,  6,  3,  2,  7,
      3,  5,  12, 6,  15, 2,  11, 12, 12, 21, 5,  1,  13, 2,  29, 38, 10,
      17, 1,  14, 1,  62, 7,  1,  14, 6,  4,  16, 6,  4,  32, 48};
  vector<int> profit = {
      21, 4,  9,  12, 5,  8,  8,  5,  14, 18, 43, 24, 3,  0,  20, 9,  0,
      24, 4,  0,  0,  7,  3,  13, 6,  5,  19, 6,  3,  14, 9,  5,  5,  6,
      4,  7,  20, 2,  13, 0,  1,  19, 4,  0,  11, 9,  6,  15, 15, 7,  1,
      25, 17, 4,  4,  3,  43, 46, 82, 15, 12, 4,  1,  8,  24, 3,  15, 3,
      6,  3,  0,  8,  10, 8,  10, 1,  21, 13, 10, 28, 11, 27, 17, 1,  13,
      10, 11, 4,  36, 26, 4,  2,  2,  2,  10, 0,  11, 5,  22, 6};  // 692206787
  //   G = 5, P = 3;
  //   group = {2, 2};
  //   profit = {2, 3};  // 2

  //   G = 10, P = 5;
  //   group = {2, 3, 5};
  //   profit = {6, 7, 8};  // 7
  cout << s.profitableSchemes(G, P, group, profit) << endl;
  return 0;
}
