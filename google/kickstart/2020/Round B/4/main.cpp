#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int W, H, L, U, R, D;
const int MAXN = 1000100;
double d[MAXN];
double d2[MAXN];

void solve(int case_num) {
  cin >> W >> H >> L >> U >> R >> D;
  double res = 0;
  int lx = R - 1, ly = U - 1;
  if (R < W)
    while (ly > 0) {
      --ly;
      ++lx;
      double mult = 1.0;
      if (lx >= W) {
        lx = W - 1;
        mult = .5;
      }
      res += mult * exp(d[lx + ly] - d[lx] - d[ly] - d2[lx + ly]);
    }
  swap(W, H);
  swap(L, U);
  swap(R, D);
  lx = R - 1, ly = U - 1;
  if (R < W)
    while (ly > 0) {
      --ly;
      ++lx;
      double mult = 1.0;
      if (lx >= W) {
        lx = W - 1;
        mult = .5;
      }
      res += mult * exp(d[lx + ly] - d[lx] - d[ly] - d2[lx + ly]);
    }
  cout << res << "\n";
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(0);
  d[0] = d2[0] = 0;
  for (int i = 1; i < MAXN; ++i) {
    d[i] = d[i - 1] + log(i);
    d2[i] = d2[i - 1] + log(2);
  }
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    solve(i);
  }
  return 0;
}
/*
8
3 3 2 2 2 2
5 3 1 2 4 2
1 10 1 3 1 5
6 4 1 3 3 4
100000 100000 2 2 2 2
100000 100000 99999 99999 99999 99999
100000 100000 9999 9999 99999 99999

1
3 3 2 2 2 2
*/