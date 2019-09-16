#include <cstdio>

int main(int argc, const char** argv) {
  long n, tmp;
  scanf("%ld", &n);
  while (n!=1) {
    if (n%2) {
      tmp = n*3+1;
      printf("%ld*3+1=%ld\n", n, tmp);
      n = tmp;
    } else {
      tmp = n/2;
      printf("%ld/2=%ld\n", n, tmp);
      n = tmp;
    }
  }
  printf("End\n");
  return 0;
}