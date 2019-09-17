#include <cstdio>
#include <cmath>

int main(int argc, const char** argv) {
  int m, n, a, b;
  scanf("%d", &n);
  if (n%2==0) {
    printf("%d\n", n/2);
    return 0;
  }
  m = int(sqrt(n));
  for (int i = 3; i < m; i+=2) {
    if (n%i==0) {
      printf("%d\n", n/i);
      return 0;
    }
  }
  return 0;
}