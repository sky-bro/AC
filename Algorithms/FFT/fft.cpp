#include <math.h>
#include <stdio.h>
#include <string.h>

#include <iostream>

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
template<typename T>
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
    for (int h = 2; h <= len; h <<= 1) { //分治后计算长度为h的DFT
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

void Conv(Complex a[], Complex b[], int len) {
    FFT(a, len);
    FFT(b, len);
    for (int i = 0; i < len; i++) a[i] = a[i] * b[i];
    IFFT(a, len);
}

int main(int argc, char const *argv[]) {
  const int N = 8;
  int A[N] = {0, 1, 2, 3, 4, 5, 6, 7};
  Rader(A, N);
  for (int i = 0; i < N; ++i) {
    cout << A[i] << " ";
  }
  cout << endl;
  return 0;
}
