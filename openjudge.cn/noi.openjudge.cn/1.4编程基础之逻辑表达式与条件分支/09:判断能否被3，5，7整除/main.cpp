#include <cstdio>

int main(int argc, const char** argv) {
  int n;
  scanf("%d", &n);
  if (n % 3 == 0) printf("3 ");
  if (n % 5 == 0) printf("5 ");
  if (n % 7 == 0) printf("7 ");
  if (n%3 && n%5 && n%7)
    printf("n");
  printf("\n");
  return 0;
}