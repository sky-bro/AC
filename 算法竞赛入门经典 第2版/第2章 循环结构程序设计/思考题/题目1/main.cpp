// 任务是输出2, 4, 6, 8, ..., 2n
// 1. 仅修改第7行
// 2. 仅修改第6行

#include <cstdio>

int main(int argc, const char **argv)
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        printf("%d\n", i);
    return 0;
}