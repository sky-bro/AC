#include <cstdio>

int main(int argc, char const *argv[])
{
  char c;
  scanf("%c", &c);

  printf("  %c\n", c);
  printf(" %c%c%c\n", c, c, c);
  printf("%c%c%c%c%c\n", c, c, c, c, c);
  return 0;
}
