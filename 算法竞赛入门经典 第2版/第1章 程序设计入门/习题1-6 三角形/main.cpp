/**
 * 输入三角形三边长度（均为正整数），判断能否构成直角三角形
 */
#include <cstdio>

inline void swap(int &a, int &b)
{
    a ^= b ^= a ^= b;
}

int main(int argc, const char **argv)
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    // 调整顺序到a<=b<=c
    if (a > b)
        swap(a, b);
    if (a > c)
        swap(a, c);
    if (b > c)
        swap(a, c);
    if (a + b <= c)
    {
        printf("not a triangle\n");
    }
    else if (a * a + b * b == c * c)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    return 0;
}