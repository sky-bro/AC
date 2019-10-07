/**
 * 输入正整数n (n<360)，输出n度的正弦、余弦函数值。提示：使用数学函数
 */
#include <cstdio>
#include <cmath>

int main(int argc, const char **argv)
{
    const double pi = acos(-1.0);
    double n;
    scanf("%lf", &n);
    n /= 180 / pi;
    printf("%.3f %.3f\n", sin(n), cos(n));
    return 0;
}