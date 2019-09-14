// 输入一个浮点数，输出这个浮点数的绝对值。

#include <cstdio>

int main(int argc, const char** argv) {
  double x;
  scanf("%lf", &x);
  printf("%.2f\n", x>=0?x:-x);
  return 0;
}