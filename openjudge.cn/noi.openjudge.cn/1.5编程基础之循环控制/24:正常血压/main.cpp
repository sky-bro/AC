#include <cstdio>

int main(int argc, const char** argv) {
  int n, a, b, cnt=0, max=0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a, &b);
    if (a < 90 || a > 140 || b < 60 || b > 90) {
      cnt = 0;
    } else {
      ++cnt;
      if (cnt > max) max=cnt;
    }
  }
  printf("%d\n", max);
  return 0;
}