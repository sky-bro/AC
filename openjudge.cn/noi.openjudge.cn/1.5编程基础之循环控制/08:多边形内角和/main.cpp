#include <cstdio>

int main(int argc, char const *argv[])
{
  int n, tmp, sum;
  scanf("%d", &n);
  sum = (n-2)*180;
  for (int i = 1; i < n; ++i) {
    scanf("%d", &tmp);
    sum -= tmp;
  }
  printf("%d\n", sum);
  return 0;
}
