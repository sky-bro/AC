#include <cstdio>

int main(int argc, const char** argv) {
  int m, n, tmp, cnt=0;
  scanf("%d%d", &m, &n);
  for (int i = m; i <= n; ++i){
    tmp = i;
    while (tmp) {
      if (tmp%10 == 2) ++cnt;
      tmp/=10;
    }
  }
  printf("%d\n", cnt);
  return 0;
}