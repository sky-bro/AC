#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

template <typename T>
T pow(T x, int n) {
  T ret = 1;
  while (n) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}

// ref: Matrix - By DanAlex https://codeforces.com/blog/entry/21189

template <typename T, std::size_t R, std::size_t C = R,
          std::size_t M = INT32_MAX>
class Matrix {
 public:
  T m[R][C];

  Matrix() { memset(m, 0, sizeof(m)); }
  /**
   * construct a matrix whose diagonal (fill at most min(R, C) number as x) is
   * filled with number x, and the rest filled with 0's
   * @param x number to be filled at the diagonal
   * @param isMainDiagonal fill main diagonal if true, else fill the
   * antidiagonal
   */
  Matrix(T x, bool isMainDiagonal = true) : Matrix() {
    if (isMainDiagonal)
      for (std::size_t i = 0; i < R && i < C; ++i) m[i][i] = x;
    else
      for (std::size_t i = 0, j = C - 1; i < R && j >= 0; --j, ++i) m[i][j] = x;
  }

  template <std::size_t C2>
  Matrix<T, R, C2, M> operator*(const Matrix<T, C, C2, M> &other) const {
    Matrix<T, R, C2, M> res;
    for (std::size_t i = 0; i < R; ++i)
      for (std::size_t k = 0; k < C; ++k)
        for (std::size_t j = 0; j < C2; ++j)
          res.m[i][j] = (res.m[i][j] + m[i][k] * other.m[k][j] % M) % M;
    return res;
  }

  Matrix<T, R, C, M> &operator*=(const Matrix<T, C, C, M> &other) {
    return *this = *this * other;
  }

  void fill(T x) {
    for (std::size_t i = 0; i < R; ++i)
      for (std::size_t j = 0; j < C; ++j) m[i][j] = x;
  }

  T sum() const {
    T res = 0;
    for (std::size_t i = 0; i < R; ++i)
      for (std::size_t j = 0; j < C; ++j) res = (res + m[i][j]) % M;
    return res;
  }
};

class Solution {
 public:
  int knightDialer(int n) {
    if (n == 1) return 10;
    Matrix<ll, 1, 10, MOD> res;
    res.fill(1);
    /*
    1 2 3
    4 5 6
    7 8 9
    * 0 #
    */
    Matrix<ll, 10, 10, MOD> x;
    vector<vector<int>> trans = {{4, 6}, {6, 8},    {7, 9}, {4, 8}, {0, 3, 9},
                                 {},     {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
    for (int i = 0; i < 10; ++i)
      for (int j : trans[i]) x.m[i][j] = 1;
    return (res * pow(x, n - 1)).sum();
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int n;
  while (cin >> n) cout << s.knightDialer(n) << endl;
  return 0;
}
