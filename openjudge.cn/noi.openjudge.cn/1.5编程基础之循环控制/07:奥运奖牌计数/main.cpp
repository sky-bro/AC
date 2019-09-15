#include <cstdio>

int main(int argc, char const *argv[])
{
  int gold=0, silver=0, brown=0, n, a, b, c;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &a, &b, &c);
    gold += a;
    silver += b;
    brown += c;
  }
  printf("%d %d %d %d\n", gold, silver, brown, gold+silver+brown);
  return 0;
}
