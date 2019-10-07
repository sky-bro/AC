/**
 * 输入正整数n，输出1+2+...+n的值
 */
#include <cstdio>

int main(int argc, const char **argv)
{
    int n;
    scanf("%d", &n);
    printf("%d\n", (1 + n) * n / 2);
    return 0;
}