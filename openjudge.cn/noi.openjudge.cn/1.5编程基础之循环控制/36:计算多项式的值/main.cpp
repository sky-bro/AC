#include <cstdio>

int main(int argc, const char** argv) {
  double x, xx = 1.0, sum = 1.0;
  int n;
  scanf("%lf%d", &x, &n);
  for (int i = 1; i <= n; ++i) {
    xx*=x;
    sum += xx;
  }
  printf("%.2f\n", sum);
  return 0;
}