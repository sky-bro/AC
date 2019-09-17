#include <cstdio>

int main(int argc, const char** argv) {
  int x=1, sum=0, n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    x*=i;
    sum += x;
  }
  printf("%d\n", sum);
  return 0;
}