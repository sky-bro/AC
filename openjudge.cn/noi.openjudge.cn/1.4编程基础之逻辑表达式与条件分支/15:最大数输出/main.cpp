#include <cstdio>

int main(int argc, const char** argv) {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  int max = a;
  if (max < b) max = b;
  if (max < c) max = c;
  printf("%d\n", max);
  return 0;
}