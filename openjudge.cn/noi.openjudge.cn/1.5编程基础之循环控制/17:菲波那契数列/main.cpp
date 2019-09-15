#include <cstdio>

int main(int argc, const char** argv) {
  int n, a=1, b=1, tmp;
  scanf("%d", &n);
  if (n == 1 || n == 2)
    printf("1\n");
  else {
    // 1 1 2 3 5
    while (--n >= 2) {
      tmp = b;
      b = a+b;
      a = tmp;
    }
    printf("%d\n", b);
  }
  return 0;
}