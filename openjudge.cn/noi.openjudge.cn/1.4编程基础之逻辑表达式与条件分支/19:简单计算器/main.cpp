#include <cstdio>

int main(int argc, const char** argv) {
  int a, b;
  char c;
  scanf("%d %d %c", &a, &b, &c);
  switch (c)
  {
  case '+':
    printf("%d\n", a+b);
    break;
  case '-':
    printf("%d\n", a-b);
    break;
  case '*':
    printf("%d\n", a*b);
    break;
  case '/':
    if (b) {
      printf("%d\n", a/b);
    } else {
      printf("Divided by zero!\n");
    }
    break;
  default:
    printf("Invalid operator!\n");
  }
  return 0;
}