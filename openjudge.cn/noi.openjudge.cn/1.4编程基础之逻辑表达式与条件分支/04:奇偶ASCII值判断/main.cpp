#include <cstdio>

int main(int argc, const char** argv) {
  char N;
  scanf("%c", &N);
  if (N % 2) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}