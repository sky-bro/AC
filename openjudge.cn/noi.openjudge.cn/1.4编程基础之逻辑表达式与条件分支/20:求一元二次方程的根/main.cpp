#include <cstdio>
#include <cmath>

const double EPS = 1e-5;

int main(int argc, char const *argv[])
{
  double a, b, c;
  scanf("%lf%lf%lf", &a, &b, &c);
  double d = b*b;
  double e = 4*a*c;
  if (d>e) {
    double f = sqrt(e-d)/(2*a);
    printf("x1=%.5f;x2=%.5f\n", (-b+f)/(2*a), f, (-b-f)/(2*a), f);
  } else if (e>d) {
    double f = sqrt(e-d)/(2*a);
    double g = -b/(2.0*a);
    if (g < EPS && g > -EPS) g = 0.0;
    printf("x1=%.5f+%.5fi;x2=%.5f-%.5fi\n", g, f, g, f);
  } else {
    printf("x1=x2=%.5f\n", -b/(2*a));
  }
  return 0;
}
