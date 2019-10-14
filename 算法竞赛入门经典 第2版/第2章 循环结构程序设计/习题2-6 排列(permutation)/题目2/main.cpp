#include <cstdio>
int main(int argc, const char **argv)
{
    double i;
    // 无限循环
    for (i = 0; i != 10; i += .1)
        printf("%.1f\n", i);
    return 0;
}