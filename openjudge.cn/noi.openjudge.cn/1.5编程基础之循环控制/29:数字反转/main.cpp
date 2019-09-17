#include <cstdio>

int main(int argc, const char** argv) {
  int n, sum=0;
  scanf("%d", &n);
  while (n) {
    sum *= 10;
    sum += n%10;
    n/=10;
  }
  printf("%d\n", sum);
  return 0;
}