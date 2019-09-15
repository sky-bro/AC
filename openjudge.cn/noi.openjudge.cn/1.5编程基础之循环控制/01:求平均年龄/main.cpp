#include <cstdio>

int main(int argc, char const *argv[])
{
  int n, sum = 0, tmp;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &tmp);
    sum += tmp;
  }
  printf("%.2f\n", 1.0*sum/n);
  return 0;
}
