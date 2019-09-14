#include <cstdio>

const double EPS = 1e-6;

int main(int argc, const char** argv) {
  double d;
  scanf("%lf", &d);

  double t_bike = 50;
  t_bike += d/3.0;

  double t_walk = 0;
  t_walk += d/1.2;

  // printf("%f, %f\n", t_walk, t_bike);
  if (t_bike - t_walk > EPS) {
    printf("Walk\n");
  } else if (t_walk - t_bike > EPS) {
    printf("Bike\n");
  } else {
    printf("All\n");
  }

  return 0;
}