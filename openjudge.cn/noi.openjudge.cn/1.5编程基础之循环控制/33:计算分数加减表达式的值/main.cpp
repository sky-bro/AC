#include <cstdio>

int main(int argc, char const *argv[])
{
  int n;
  scanf("%d", &n);
  double sum = 0.0;
  for (int i = 1; i <= n; ++i) {
    if (i%2) {
      sum += 1.0/i;
    } else {
      sum -= 1.0/i;
    }
  }
  printf("%.4f\n", sum);
  return 0;
}
