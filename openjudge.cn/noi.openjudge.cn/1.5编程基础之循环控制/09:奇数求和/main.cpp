#include <cstdio>

int main(int argc, char const *argv[])
{
  int m, n, sum=0;
  scanf("%d%d", &m, &n);
  m += (m%2==0);
  n -= (n%2==0);
  if (m <= n) {
    sum = (m+n)*((n-m)/2+1)/2;
  }
  printf("%d\n", sum);
  return 0;
}
