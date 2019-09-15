#include <cstdio>

int main(int argc, char const *argv[])
{
  int n, max, min, tmp;
  scanf("%d%d", &n, &max);
  min = max;
  for (int i = 1; i < n; ++i) {
    scanf("%d", &tmp);
    if (tmp > max) max = tmp;
    if (tmp < min) min = tmp;
  }
  printf("%d\n", max-min);
  return 0;
}
