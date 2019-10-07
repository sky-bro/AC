// 方法1，一位一位反向输出
#include <cstdio>
int main(int argc, const char **argv)
{
    int n;
    scanf("%d", &n);
    printf("%d%d%d\n", n % 10, n / 10 % 10, n / 100);
    return 0;
}