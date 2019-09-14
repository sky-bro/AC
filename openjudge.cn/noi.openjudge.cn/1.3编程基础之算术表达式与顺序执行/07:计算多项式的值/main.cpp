// 对于多项式f(x) = ax3 + bx2 + cx + d 和给定的a, b, c, d, x，计算f(x)的值。

#include <cstdio>

double x, a, b, c, d;

inline double f(double x) {
  return x*(c+x*(b+a*x)) + d;
}

int main(int argc, const char** argv) {
  scanf("%lf%lf%lf%lf%lf", &x, &a, &b, &c, &d);
  printf("%.7f\n", f(x));
  return 0;
}