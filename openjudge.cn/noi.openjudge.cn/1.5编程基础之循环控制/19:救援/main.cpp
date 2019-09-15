#include <cstdio>
#include <cmath>

inline double distance(double x, double y) {
  return sqrt(x*x + y*y);
}

int main(int argc, char const *argv[])
{
  int n, num;
  double time = 0, x, y;
  scanf("%d", &n);
  while (n > 0) {
    scanf("%lf%lf%d", &x, &y, &num);
    
    time += distance(x, y)*2/50;
    time += 1.5*num;
    --n;
  }
  printf("%d\n", int(ceil(time)));
  return 0;
}
