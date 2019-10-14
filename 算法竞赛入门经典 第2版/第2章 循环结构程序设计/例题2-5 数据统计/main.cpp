#define LOCAL
#include <cstdio>
const int INF = 1000000000;

int main(int argc, char const *argv[])
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int x, n = 0, min = INF, max = -INF, s = 0;
    while (scanf("%d", &x) == 1)
    {
        s += x;
        if (x < min)
            min = x;
        if (x > max)
            max = x;
        // printf("x = %d, min = %d, max = %d\n", x, min, max);
        n++;
    }
    printf("%d %d %.3f\n", min, max, double(s) / n);
    return 0;
}
