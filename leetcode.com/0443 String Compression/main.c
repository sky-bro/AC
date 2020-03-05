#include <stdio.h>

int compress(char* chars, int n) {
  int res = 0;
  for (int i = 0; i < n;) {
    int cnt = 1;
    chars[res++] = chars[i++];
    for (; i < n && chars[i] == chars[i - 1]; ++i) ++cnt;
    if (cnt != 1) {
      char saved = 0;
      if (res == i - 1) {
        chars[res++] = '2';
      } else {
        // bug 1: sprintf will add '\0' to terminate string (fixed)
        // bug 2: for chars = ['a', 'a'], sprintf will cause overflow by 1 char:
        // chars[2] = '\0' (fixed)
        res += sprintf(chars + res, "%d", cnt);
      }
    }
  }
  return res;
}

int main(int argc, char const* argv[]) {
  // char chars[] = "aabbccc";
  char chars[] = "aa";
  printf("%d\n%s\n", compress(chars, 2), chars);
  return 0;
}
