#include <cstdio>

int main(int argc, const char** argv) {
  int N, M, X, m=0;
  scanf("%d%d%d", &M, &N, &X);
  while (1) {
    // 补充满体力需要M/N(+1)
    if (M%N==0)X-=M/N;
    else X-=M/N+1;
    // X为负表示不够补充满体力，结束循环
    if (X<0)break;
    // 增加战斗力
    N += M/N;
  }
  printf("%d\n", N);
  return 0;
}