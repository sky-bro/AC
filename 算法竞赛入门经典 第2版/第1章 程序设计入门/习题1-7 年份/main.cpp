/**
 * 输入年份，判断是否为闰年
 */
#include <cstdio>

int main(int argc, const char **argv)
{
    int n;
    scanf("%d", &n);
    if (n % 4 || !(n % 100) && (n % 400))
    {
        printf("no\n");
    }
    else
    {
        printf("yes\n");
    }
    return 0;
}