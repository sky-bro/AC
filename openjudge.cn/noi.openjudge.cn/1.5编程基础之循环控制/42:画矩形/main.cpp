#include <cstdio>

int main(int argc, const char** argv) {
  int w, h, fill;
  char c;
  scanf("%d %d %c %d", &h, &w, &c, &fill);
  for (int i = 0; i < w; ++i)
    printf("%c", c);
  printf("\n");
  for (int i = 1; i < h-1; ++i) {
    printf("%c", c);
    for (int j = 1; j < w-1; ++j) {
      if (fill) {
        printf("%c", c);
      } else {
        printf(" ");
      }
    }
    printf("%c\n", c);
  }
  for (int i = 0; i < w; ++i)
    printf("%c", c);
  printf("\n");
  return 0;
}