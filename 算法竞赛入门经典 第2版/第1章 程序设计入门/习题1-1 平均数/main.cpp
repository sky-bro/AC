/**
 * 输入3个整数，输出他们的平均值，保留3位小数
 */

#include <cstdio>

int main(int argc, const char **argv)
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%.3f\n", (a + b + c) / 3.0);
    return 0;
}