#include <cstdio>

int main(int argc, char const *argv[])
{
  int n; scanf("%d", &n);
  double sum = 0, tmp;
  for (int i = 0; i < n; ++i) {
    scanf("%lf", &tmp);
    sum += tmp;
  }
  printf("%.4f\n", sum/n);
  return 0;
}
