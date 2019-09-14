// 给定一个整数，判断该数是奇数还是偶数。

#include <cstdio>

int main(int argc, const char** argv) {
  int N;
  scanf("%d", &N);
  if (N % 2) {
    printf("odd\n");
  } else {
    printf("even\n");
  }
  return 0;
}