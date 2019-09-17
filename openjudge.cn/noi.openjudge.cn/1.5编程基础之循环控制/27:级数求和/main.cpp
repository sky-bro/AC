#include <cstdio>

int main(int argc, const char** argv) {
  int k, n=0; double sum = 0.0;
  scanf("%d", &k);
  while (sum <= k) {
    ++n;
    sum += 1.0/n;
  }
  printf("%d\n", n);
  return 0;
}