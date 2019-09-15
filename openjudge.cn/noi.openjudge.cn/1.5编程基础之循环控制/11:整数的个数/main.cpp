#include <cstdio>

int main(int argc, char const *argv[])
{
  int k, tmp, a=0, b=0, c=0;
  scanf("%d", &k);
  for (int i = 0; i < k; ++i) {
    scanf("%d", &tmp);
    if (tmp == 1) {
      ++a;
    } else if (tmp == 5) {
      ++b;
    } else if (tmp == 10) {
      ++c;
    }
  }
  printf("%d\n%d\n%d\n", a, b, c);
  return 0;
}
