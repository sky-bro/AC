#include <cstdio>

const double pi = 3.14;
const double c = 4*pi/3;

int main(int argc, const char** argv) {
  double r;
  scanf("%lf", &r);
  printf("%.2f\n", c*r*r*r);
  return 0;
}