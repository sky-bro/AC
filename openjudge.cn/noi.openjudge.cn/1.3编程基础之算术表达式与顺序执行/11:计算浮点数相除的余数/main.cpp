// 计算两个双精度浮点数a和b的相除的余数，a和b都是正数的。这里余数（r）的定义是：a = k * b + r，其中 k是整数， 0 <= r < b。

#include <cstdio>

int main(int argc, const char** argv) {
  double a, b, r;
  scanf("%lf%lf", &a, &b);
  r = a - int(a/b)*b;
  printf("%g\n", r);
  return 0;
}

/*
注意：输出时小数尾部没有多余的0，可以用下面这种格式：
double x;
x = 1.33;
printf("%g", x);
*/