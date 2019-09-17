#include <iostream>

using namespace std;

int main(int argc, const char** argv) {
  int n;
  scanf("%d", &n);
  int tmp, a=0, b=0, c=0, d=0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &tmp);
    if (tmp < 19) ++a;
    else if (tmp < 36) ++b;
    else if (tmp < 61) ++c;
    else ++d;
  }
  printf("%.2f%%\n", 100.0*a/n);
  printf("%.2f%%\n", 100.0*b/n);
  printf("%.2f%%\n", 100.0*c/n);
  printf("%.2f%%\n", 100.0*d/n);
  return 0;
}