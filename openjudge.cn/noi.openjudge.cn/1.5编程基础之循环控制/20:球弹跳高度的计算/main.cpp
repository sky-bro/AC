#include <cstdio>

int main(int argc, char const *argv[])
{
  double h, sum;
  scanf("%lf", &h);
  sum = h;
  h /= 2;
  for (int i = 1; i < 10; ++i) {
    sum += 2*h;
    h /= 2;
  }
  printf("%g\n%g\n", sum, h);
  return 0;
}
