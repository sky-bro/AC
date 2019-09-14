// 给出圆的半径，求圆的直径、周长和面积。
#include <cstdio>

const double pi = 3.14159;

int main(int argc, const char** argv) {
  double r;
  scanf("%lf", &r);
  printf("%.4f %.4f %.4f\n", 2*r, 2*pi*r, pi*r*r);
  return 0;
}