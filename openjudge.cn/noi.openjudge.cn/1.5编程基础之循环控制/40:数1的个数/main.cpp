#include <cstdio>

int main(int argc, const char** argv) {
  int n, tmp, cnt=0;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i){
    tmp = i;
    while (tmp) {
      if (tmp%10 == 1) ++cnt;
      tmp/=10;
    }
  }
  printf("%d\n", cnt);
  return 0;
}