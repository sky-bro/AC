#include <cstdio>

int main(int argc, char const *argv[])
{
  int n, max, tmp;
  scanf("%d%d", &n, &max);
  for (int i = 1; i < n; ++i) {
    scanf("%d", &tmp);
    if (tmp > max) max = tmp;
  }
  printf("%d\n", max);
  return 0;
}
