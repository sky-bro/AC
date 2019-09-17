// 不用数组 150+ms
#include <cstdio>

int main(int argc, const char** argv) {
  int N, M;
  scanf("%d%d", &N, &M);
  if (M == 1) {
    for (int i = 1; i < N; ++i) printf("%d,", i);
    printf("%d\n", N);
  } else if (M==2) {
    N -= (N%2==0);
    for (int i = 1; i < N; i+=2) printf("%d,", i);
    printf("%d\n", N);
  } else {
    int light;
    printf("1");
    for (int i = 3; i <= N; ++i) {
      light = (i%2==0);
      for (int j = 3; j <= M && j <= i; ++j) {
        if (i%j==0) light = !light;
      }
      if (light==0) {
        printf(",%d", i);
      }
    }
    printf("\n");
  }
  return 0;
}