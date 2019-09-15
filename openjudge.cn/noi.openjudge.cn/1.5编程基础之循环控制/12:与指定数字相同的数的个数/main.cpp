#include <cstdio>

int main(int argc, char const *argv[])
{
  int k, m, tmp, cnt=0;
  scanf("%d%d", &k, &m);
  for (int i = 0; i < k; ++i) {
    scanf("%d", &tmp);
    if (tmp == m) {
      ++cnt;
    }
  }
  printf("%d\n", cnt);
  return 0;
}
