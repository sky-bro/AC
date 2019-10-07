#include <cstdio>

int main(int argc, const char **argv)
{
    int a, b, c, t;
    scanf("%d%d%d", &a, &b, &c);
    // 相当于选择排序，每次选择最小的排到前面
    if (a > b)
    {
        t = a;
        a = b;
        b = t;
    } // 执行完毕后a<=b
    if (a > c)
    {
        t = a;
        a = c;
        c = t;
    } // 执行完毕后a<=c，且a<=b依然成立，a顺序调整完毕
    if (b > c)
    {
        t = b;
        b = c;
        c = t;
    } // b和c调整顺序
    printf("%d %d %d\n", a, b, c);
    return 0;
}