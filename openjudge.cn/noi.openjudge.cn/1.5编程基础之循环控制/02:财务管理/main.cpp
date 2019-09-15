#include <cstdio>

int main(int argc, char const *argv[])
{
  double sum = 0, tmp;
  for (int i = 0; i < 12; ++i) {
    scanf("%lf", &tmp);
    sum += tmp;
  }
  printf("$%.2f\n", sum/12.0);
  return 0;
}
