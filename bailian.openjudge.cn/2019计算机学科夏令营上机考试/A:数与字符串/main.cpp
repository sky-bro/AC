#include <cstdio>
#include <cstring>
#include <cmath>

int main(int argc, char const *argv[])
{
  char a[10];
  char b[10] = "999999";
  int len;
  w:
  while (true) {
    scanf("%s", a); len = strlen(a);
    if (a[0] == '0') break;
    if (len == 1) {
      printf("%s\n", a);
    } else {
      int i = 0;
      for (; i < len-1; ++i) {
        if (a[i] < '9') {
          b[len-1] = 0;
          printf("%s\n", b);
          b[len-1] = '9';
          break;
        }
      }
      if (i == len-1) printf("%s\n", a);
    }
  }
  return 0;
}
