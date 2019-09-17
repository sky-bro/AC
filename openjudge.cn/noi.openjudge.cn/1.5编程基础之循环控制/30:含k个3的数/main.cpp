#include <cstdio>

int main(int argc, const char** argv) {
  int n, k;
  scanf("%d%d", &n, &k);
  if (n%19 == 0) {
    while (n) {
      if (n%10 == 3) --k;
      n/=10;
    }
    if (k==0) {
      printf("YES\n");
      return 0;
    }
  }
  
  printf("NO\n");
  return 0;
}