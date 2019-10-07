// 方法2，算出反转结果再用%d输出
#include <cstdio>
int main(int argc, const char **argv)
{
    int n, m;
    scanf("%d", &n);
    m = n % 10 * 100 + n / 10 % 10 * 10 + n / 100;
    printf("%03d\n", m);
    return 0;
}