#include <cstdio>
#include <cmath>

inline bool is_prime(int x) {
  if (x==2) return true;
  int m = int(sqrt(x));
  for (int i = 2; i <= m; ++i) {
    if (x%i==0) return false;
  }
  return true;
}

int main(int argc, const char** argv) {
  int cnt = 1, n, x=1, p=2;
  scanf("%d", &n);
  while (cnt < n) {
    x+=2;
    if (is_prime(x)) {
      p = x;
      ++cnt;
    }
  }
  printf("%d\n", p);
  return 0;
}