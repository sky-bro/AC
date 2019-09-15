#include <cstdio>

int main(int argc, const char** argv) {
  int n; double r=1, x=1.001, sum;
  scanf("%lf%d", &sum, &n);
  while (n) {
    if (n&1){
      r *= x;
    }
    x *= x;
    n >>= 1;
  }
  printf("%.4f\n", sum*r);
  return 0;
}