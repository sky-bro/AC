#include <cstdio>

int main(int argc, const char** argv) {
  int w; char emergency;
  int cost = 8;
  scanf("%d %c", &w, &emergency);
  if (emergency == 'y') {
    cost += 5;
  }
  if (w > 1000) {
    cost += ((w-1000 + 499) / 500) * 4;
  }
  printf("%d\n", cost);
  return 0;
}