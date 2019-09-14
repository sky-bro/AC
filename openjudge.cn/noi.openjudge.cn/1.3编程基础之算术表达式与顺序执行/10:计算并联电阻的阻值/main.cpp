// 对于阻值为r1和r2的电阻，其并联电阻阻值公式计算如下：
// R = 1/(1/r1 + 1/r2)

#include <cstdio>

int main(int argc, const char** argv) {
  float r1, r2;
  scanf("%f%f", &r1, &r2);
  printf("%.2f\n", 1/(1/r1+1/r2));
  return 0;
}