#include <cstring>
#include <iostream>

using namespace std;

// matrix fast pow

typedef long long ll;
const int MOD = 1e9 + 7;  // for this problem, no need to mod, n <= 30

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
  int fib(int N) {
    Matrix<ll, 1, 2, MOD> res;
    res.m[0][1] = 1;
    if (N < 2) return N;
    Matrix<ll, 2, 2, MOD> x;  // transition matrix
    x.fill(1);
    x.m[0][0] = 0;
    return (res * pow(x, N - 1)).m[0][1];
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int N;
  while (cin >> N) cout << s.fib(N) << endl;
  return 0;
}
