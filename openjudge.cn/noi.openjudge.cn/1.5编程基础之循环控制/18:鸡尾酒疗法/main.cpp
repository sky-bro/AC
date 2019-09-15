#include <cstdio>

int main(int argc, char const *argv[])
{
  int n, a, b;
  double x, y;
  scanf("%d%d%d", &n, &a, &b);
  x = 1.0*b/a;
  while (--n) {
    scanf("%d%d", &a, &b);
    y = 1.0*b/a;
    if (x - y > 0.05) {
      printf("worse\n");
    } else if (y - x > 0.05) {
      printf("better\n");
    } else {
      printf("same\n");
    }
  }
  return 0;
}
