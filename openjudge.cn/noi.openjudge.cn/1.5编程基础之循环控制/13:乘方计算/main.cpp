#include <cstdio>

int main(int argc, const char** argv) {
  int n, r=1, x;
  scanf("%d%d", &x, &n);
  while (n) {
    if (n&1){
      r *= x;
    }
    x *= x;
    n >>= 1;
  }
  printf("%d\n", r);
  return 0;
}