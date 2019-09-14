#include <cstdio>

int main(int argc, const char** argv) {
  int n;
  scanf("%d", &n);
  if (n == 1 || n == 3 || n == 5) {
    printf("NO\n");
  } else {
    printf("YES\n");
  }
  return 0;
}