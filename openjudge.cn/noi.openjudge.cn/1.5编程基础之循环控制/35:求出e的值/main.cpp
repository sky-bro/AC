#include <cstdio>

int main(int argc, const char** argv) {
  int n;
  double x = 1.0;
  double sum = 1.0;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    x*=i;
    sum += 1.0/x;
  }
  printf("%.10f\n", sum);
  return 0;
}