#include <cstdio>

int main(int argc, const char** argv) {
  int n, c;
  scanf("%d", &n);
  if (n==0) {
    scanf("%d", &c);
    printf("0\n");
    return 0;
  }
  for (int i = n; i > 0; --i) {
    scanf("%d", &c);
    printf("%d ", c*i);
  }
  scanf("%d", &c);
  printf("\n");
  return 0;
}