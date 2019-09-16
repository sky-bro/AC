#include <cstdio>

int main(int argc, char const *argv[])
{
  int m, n, tmp, cnt=0;
  scanf("%d%d", &m, &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &tmp);
    if (tmp > m) {
      ++cnt;
      continue;
    }
    m-=tmp;
  }
  printf("%d\n", cnt);
  return 0;
}
