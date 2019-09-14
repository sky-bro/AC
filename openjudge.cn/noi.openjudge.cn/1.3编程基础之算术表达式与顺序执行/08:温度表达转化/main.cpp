// 利用公式 C = 5 * (F-32) / 9 （其中C表示摄氏温度，F表示华氏温度） 进行计算转化。

#include <cstdio>

int main(int argc, const char** argv) {
  double f;
  scanf("%lf", &f);
  printf("%.5f\n", 5*(f-32)/9);
  return 0;
}