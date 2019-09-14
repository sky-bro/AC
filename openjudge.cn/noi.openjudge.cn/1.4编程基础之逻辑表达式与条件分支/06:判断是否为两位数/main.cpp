// 判断一个正整数是否是两位数（即大于等于10且小于等于99）。

#include <cstdio>

int main(int argc, const char** argv) {
  int N;
  scanf("%d", &N);
  if (N > 9 && N < 100) {
    printf("1\n");
  } else {
    printf("0\n");
  }
  return 0;
}