#include <cstdio>

int main(int argc, const char** argv) {
  int a, b;
  scanf("%d%d", &a, &b);
  if (a > 9 || b > 19) {
    printf("1\n");
  } else {
    printf("0\n");
  }
  return 0;
}