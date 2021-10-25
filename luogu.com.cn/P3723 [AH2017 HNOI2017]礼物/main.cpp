// from: https://www.luogu.com.cn/problem/P3723
#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);

class Complex {
 public:
  double r, i;
  Complex(double r = 0.0, double i = 0.0) : r(r), i(i) {}
  Complex operator+(const Complex &x) { return Complex(r + x.r, i + x.i); }
  Complex operator-(const Complex &x) { return Complex(r - x.r, i - x.i); }
  Complex operator*(const Complex &x) {
    return Complex(r * x.r - i * x.i, i * x.r + r * x.i);
  }
};

//雷德算法--倒位序
template <typename T>
void Rader(T F[], int len) {
  int j = len >> 1;
  for (int i = 1; i < len - 1; i++) {
    if (i < j) swap(F[i], F[j]);
    int k = len >> 1;
    while (j >= k) {
      j -= k;
      k >>= 1;
    }
    if (j < k) j += k;
  }
}

void FFT(Complex F[], int len, int on = 1) {
  // len = 2^k
  Rader(F, len);
  for (int h = 2; h <= len; h <<= 1) {  //分治后计算长度为h的DFT
    //单位复根e^(2*PI/m)用欧拉公式展开
    Complex wn(cos(-on * 2 * PI / h), sin(-on * 2 * PI / h));
    for (int j = 0; j < len; j += h) {
      Complex w(1, 0);  //旋转因子
      for (int k = j; k < j + h / 2; k++) {
        Complex t = w * F[k + h / 2];
        F[k + h / 2] = F[k] - t;
        F[k] = F[k] + t;
        w = w * wn;  //更新旋转因子
      }
    }
  }
  if (on == -1)
    for (int i = 0; i < len; i++) F[i].r /= len;
}

void IFFT(Complex F[], int len) { FFT(F, len, -1); }

const int N = 65536 * 2;
int A[N], B[N];
Complex F1[N], F2[N];

void solve() {
  int n, m, res = 0;
  cin >> n >> m;
  /*
  (x + c - y)^2 = (x+c)^2 + y^2 -2y(x+c)
                = x^2 + y^2 + c^2 + 2(x - y)c -2xy
  */
  int b = 0;
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
    res += A[i] * A[i];
    b += A[i];
    F1[i] = A[i];
  }
  for (int i = n - 1; i >= 0; --i) {
    cin >> B[i];
    res += B[i] * B[i];
    b -= B[i];
    F2[i] = B[i];
  }
  for (int i = 0; i < n; ++i) F2[i + n] = F2[i];
  int c1 = int(floor(b * 1.0 / n)), c2 = int(ceil(b * 1.0 / n));
  res += min(n * c1 * c1 - 2 * c1 * b, n * c2 * c2 - 2 * c2 * b);

  int len = 1;
  while (len < n * 2) len <<= 1;
  FFT(F1, len);
  FFT(F2, len);
  for (int i = 0; i < len; ++i) F1[i] = F1[i] * F2[i];
  IFFT(F1, len);
  int mx = INT32_MIN;
  for (int i = 0; i < n; ++i) mx = max(mx, int(F1[n + i - 1].r + 0.5));
  res -= 2 * mx;
  cout << res << endl;
}

int main(int argc, char const *argv[]) {
  solve();
  return 0;
}
