#include <cstdio>

int main(int argc, const char** argv) {
  char c; int n; float f; double d;
  scanf("%c%d%f%lf", &c, &n, &f, &d);
  printf("%c %d %.6f %.6f", c, n, f, d);
  return 0;
}