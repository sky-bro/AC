#include <cstdio>

int main(int argc, const char** argv) {
  int x, y;
  scanf("%d%d", &x, &y);

  if (x <= 1 && x >= -1 && y >= -1 && y <= 1) {
    printf("yes\n");
  } else {
    printf("no\n");
  }
  return 0;
}