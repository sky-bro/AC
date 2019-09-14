#include <cstdio>

int main(int argc, const char** argv) {
  int a, b;
  scanf("%d%d", &a, &b);
  int cnt = 0;
  cnt += a<60;
  cnt += b<60;
  // printf("%d\n", cnt);
  printf("%d\n", cnt==1);
  return 0;
}