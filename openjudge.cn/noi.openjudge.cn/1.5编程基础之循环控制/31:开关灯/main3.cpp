// 用数组 10ms

#include <cstdio>

bool lights[5001];

int main(int argc, char const *argv[])
{
  int N, M;
  scanf("%d%d", &N, &M);
  printf("1");
  for (int i = 1; i <= M; ++i) 
    for (int j = i; j <= N; j+=i)
      lights[j] = !lights[j];
  for (int i = 2; i <= N; ++i)
    if (lights[i]) printf(",%d", i);
  printf("\n");
  return 0;
}
