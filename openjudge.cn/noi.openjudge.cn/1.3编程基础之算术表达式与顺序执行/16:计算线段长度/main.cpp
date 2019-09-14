#include <cstdio>
#include <cmath>

int main(int argc, const char** argv) {
  double Xa, Ya, Xb, Yb;
  scanf("%lf%lf%lf%lf", &Xa, &Ya, &Xb, &Yb);
  double diffX = Xa - Xb;
  double diffY = Ya - Yb;
  printf("%.3f", sqrt(diffX*diffX + diffY*diffY));
  return 0;
}