// 用数组 4ms

#include <cstdio>

bool lights[5001];

int main(int argc, char const *argv[])
{
  int N, M;
  scanf("%d%d", &N, &M);
  printf("1");

  if (M == 1) {
    // M = 1
    for (int i = 2; i <= N; ++i) printf(",%d", i);
  } else if (M==2) {
    // M = 2
    for (int i = 3; i <= N; i+=2) printf(",%d", i);
  } else {
    for (int i=3; i <= N; ++i) lights[i] = (i%2==0);
    // M >= 3
    for (int i = 3; i <= M; ++i) {
      for (int j = i; j <= N; j += i) {
        lights[j] = !lights[j];
      }
    }
    for (int i = 3; i <= N; ++i) {
      if (lights[i]==0) printf(",%d", i);
    }
  }

  printf("\n");
  return 0;
}
