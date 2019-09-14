// 给出圆的半径，求圆的直径、周长和面积。
#include <cstdio>

const double pi = 3.14159;

int main(int argc, const char** argv) {
  int h, r;
  scanf("%d%d", &h, &r);
  printf("%d", int(20000/(pi*r*r*h)+1));
  return 0;
}