#include <cstdio>

int main(int argc, const char** argv) {
  int n; double r=1, x, sum;
  scanf("%lf%lf%d", &x, &sum, &n);
  x = x/100 + 1;
  while (n) {
    if (n&1){
      r *= x;
    }
    x *= x;
    n >>= 1;
  }
  printf("%d\n", int(sum*r));
  return 0;
}