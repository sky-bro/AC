#include <cstdio>

int main(int argc, const char** argv) {
  int n;
  scanf("%d", &n);
  while (n) {
    printf("%d ", n%10);
    n/=10;
  }
  printf("\n");
  return 0;
}