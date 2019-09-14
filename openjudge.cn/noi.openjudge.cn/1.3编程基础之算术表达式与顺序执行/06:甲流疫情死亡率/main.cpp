#include <cstdio>

int main(int argc, const char** argv) {
  int a, b;
  scanf("%d%d", &a, &b);
  printf("%.3f%%\n", b*(100.0)/a);
  return 0;
}