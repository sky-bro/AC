#include <cstdio>

int main(int argc, char const *argv[])
{
  int q=2, p=1, tmp, n;
  scanf("%d", &n);
  double sum = 0.0;
  for (int i = 0; i < n; ++i) {
    sum += 1.0*q/p;
    tmp = q;
    q = p+q;
    p = tmp;
  }
  printf("%.4f\n", sum);
  return 0;
}
