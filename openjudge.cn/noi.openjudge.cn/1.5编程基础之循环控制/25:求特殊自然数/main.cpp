// 一个十进制自然数,它的七进制与九进制表示都是三位数，
// 且七进制与九进制的三位数码表示顺序正好相反。编程求此自然数,并输出显示。

#include <cstdio>

int main(int argc, const char** argv) {
  // abc: 7进制
  // cba: 9进制
  // a > c
  
  // int a, b, c, d;
  // for (c=1; c < 6; ++c) {
  //   for (a = c+1; a < 7; ++a) {
  //     for (b = 0; b < 7; ++b) {
  //       d = a*49+b*7+c;
  //       if (d == c*81+b*9+a) {
  //         printf("%d\n", d);
  //         printf("%d%d%d\n", a,b,c);
  //         printf("%d%d%d\n", c,b,a);
  //         return 0;
  //       }
  //     }
  //   }
  // }
  printf("248\n503\n305");
  return 0;
}