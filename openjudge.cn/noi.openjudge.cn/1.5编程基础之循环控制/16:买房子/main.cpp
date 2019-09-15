#include <cstdio>

int main(int argc, const char** argv) {
  int N; double K, sum=200;
  scanf("%d%lf", &N, &K);
  K = K/100 + 1;
  int n = 1;
  while (n!=21) {
    if (sum - n*N < 0) {
      break;
    }
    sum *= K; ++n;
  }
  if (n==21) {
    printf("Impossible\n");
  } else {
    printf("%d\n", n);
  }
  return 0;
}