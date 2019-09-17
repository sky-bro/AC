#include <cstdio>

int main(int argc, const char** argv) {
  int n, cnt=0, x, tmp;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    tmp = x%10; x/=10;
    for (int j = 1; j < 4; ++j) {
      tmp-=x%10;
      x/=10;
    }
    if (tmp>0) ++cnt;
  }
  printf("%d\n", cnt);
  return 0;
}