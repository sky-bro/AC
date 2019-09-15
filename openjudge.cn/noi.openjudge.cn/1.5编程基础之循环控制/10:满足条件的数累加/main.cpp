#include <cstdio>

int main(int argc, char const *argv[])
{
  int m, n, sum=0;
  scanf("%d%d", &m, &n);
  if (m%17)
    m += (17 - m%17);
  n -= (n%17);
  if (m <= n) {
    sum = (m+n)*((n-m)/17+1)/2;
  }
  printf("%d\n", sum);
  return 0;
}
