// 给出一个等差数列的前两项a1，a2，求第n项是多少。
#include <cstdio>

int main(int argc, const char** argv) {
  int a1, a2, n;
  scanf("%d%d%d", &a1, &a2, &n);
  printf("%d\n", a1+(a2-a1)*(n-1));
  return 0;
}