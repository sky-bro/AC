// 输入两个整数，比较它们的大小。

#include <cstdio>

int main(int argc, const char** argv) {
  long x, y;
  scanf("%ld%ld", &x, &y);
  if (x > y) {
    printf(">\n");
  } else if (x == y) {
    printf("=\n");
  } else {
    printf("<\n");
  }
  return 0;
}