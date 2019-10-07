/**
 * 一件衣服95元，若消费满300元，可打八五折。输入购买衣服件数，输出需要支付的金额（单位：元），保留两位小数
 */
#include <cstdio>

int main(int argc, const char **argv)
{
    int n;
    scanf("%d", &n);
    printf("%.2f\n", n < 4 ? n * 95 : n * 95 * 0.85);
    return 0;
}