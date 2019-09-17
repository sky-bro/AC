#include <cstdio>

int main(int argc, const char** argv) {
  int sum=0, n, tmp; 
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    if (i%7) {
      tmp = i;
      while (tmp) {
        if (tmp%10==7) {
          break;
        }
        tmp/=10;
      }
      if (!tmp) {
        // printf("%d\n", i);
        sum += i*i;
      }
    }
  }
  printf("%d\n", sum);
  return 0;
}