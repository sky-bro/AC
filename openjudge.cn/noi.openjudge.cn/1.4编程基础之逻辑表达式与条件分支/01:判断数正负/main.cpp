// 给定一个整数N，判断其正负。

#include <cstdio>

int main(int argc, const char** argv) {
  int N;
  scanf("%d", &N);
  if (N > 0) {
    printf("positive");
  } else if (N == 0) {
    printf("zero");
  } else {
    printf("negative");
  }
  return 0;
}