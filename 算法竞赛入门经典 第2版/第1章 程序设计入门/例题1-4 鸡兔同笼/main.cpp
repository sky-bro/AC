/**
 * 已知鸡和兔总数量为n，总腿数为m。输入n和m，依次输出鸡的数目和兔的数目
 * n = x + y;
 * m = 2*x + 4*y;
 */
#include <cstdio>

int main(int argc, const char **argv)
{
    int n, m, x, y;
    scanf("%d%d", &n, &m);
    x = (4 * n - m) / 2;
    y = n - x;
    if (m % 2 || x < 0 || y < 0)
        printf("No answer\n");
    else
        printf("%d %d\n", x, y);
    return 0;
}