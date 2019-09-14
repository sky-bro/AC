#include <cstdio>

const double pi = 3.14159;

int main(int argc, const char** argv) {
  int n, x, y;
  scanf("%d%d%d", &n, &x, &y);
  n = n - (y/x+(y%x != 0));
  printf("%d\n", n);
  return 0;
}