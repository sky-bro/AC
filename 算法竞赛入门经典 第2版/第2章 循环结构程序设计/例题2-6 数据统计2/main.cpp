#define LOCAL
#include <cstdio>
const int INF = 1000000000;

int main(int argc, char const *argv[])
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int x, n = 0, min, max, s, kase = 0;
    while (scanf("%d", &n) == 1 && n)
    {
        s = 0;
        min = INF;
        max = -INF;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &x);
            s += x;
            if (x < min)
                min = x;
            if (x > max)
                max = x;
        }
        if (kase)
            printf("\n");
        printf("Case %d: %d %d %.3f\n", ++kase, min, max, double(s) / n);
    }
    return 0;
}
