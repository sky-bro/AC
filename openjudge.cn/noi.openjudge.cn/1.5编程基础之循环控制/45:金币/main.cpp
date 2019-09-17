#include <cstdio>

int main(int argc, const char** argv) {
  int n, i=1, sum=0;
  scanf("%d", &n);
  while (n) {
    if (n > i) {
      sum += (i*i);
      n -= i;
      ++i;
    } else {
      sum += (i*n);
      break;
    }
  }
  printf("%d\n", sum);
  return 0;
}