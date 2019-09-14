// 海伦公式
#include <cstdio>
#include <cmath>

inline double lenAB(float xA, float yA, float xB, float yB) {
  double diffX = xA - xB;
  double diffY = yA - yB;
  // printf("diffX: %f\n", diffX);
  // printf("diffY: %f\n", diffY);
  return sqrt(diffX*diffX + diffY*diffY);
}

int main(int argc, const char** argv) {
  float x1, y1, x2, y2, x3, y3;
  scanf("%f%f%f%f%f%f", &x1, &y1, &x2, &y2, &x3, &y3);
  double a, b, c, p;
  a = lenAB(x1, y1, x2, y2);
  b = lenAB(x1, y1, x3, y3);
  c = lenAB(x3, y3, x2, y2);
  p = (a+b+c)/2;
  // printf("%f\t%f\t%f\n", a, b, c);
  // 海伦公式
  double s = sqrt(p*(p-a)*(p-b)*(p-c));
  printf("%.2f\n", s);
  return 0;
}
