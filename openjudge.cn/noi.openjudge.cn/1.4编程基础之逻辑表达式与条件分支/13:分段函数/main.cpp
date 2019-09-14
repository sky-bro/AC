#include <cstdio>

int main(int argc, const char** argv) {
  double x;
  scanf("%lf", &x);
  if (x < 5) {
    printf("%.3f\n", 2.5-x);
  } else if (x < 10) {
    printf("%.3f\n", 2-1.5*(x-3)*(x-3));
  } else {
    printf("%.3f\n", x/2-1.5);
  }
  return 0;
}