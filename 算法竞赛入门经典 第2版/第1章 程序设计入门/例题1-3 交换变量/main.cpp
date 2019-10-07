#include <cstdio>
int main(int argc, const char **argv)
{
    int a, b, t;
    scanf("%d%d", &a, &b);
    // 要的是结果，不要在意过程，可直接输出结果
    // printf("%d %d\n", b, a);

    // 推荐使用下面的三变量法
    t = a;
    a = b;
    b = t;

    // 两变量法: 这种方法需要加一个判断
    // if (a == b)
    //     return;

    // 1. 加法
    /*
    a = a + b;
    b = a - b;
    a = a - b;
    */

    // 2. 异或
    // 2.1
    a ^= b;
    b ^= a;
    a ^= b;
    // 2.2
    // a ^= b ^= a ^= b;

    printf("%d %d\n", a, b);
    return 0;
}