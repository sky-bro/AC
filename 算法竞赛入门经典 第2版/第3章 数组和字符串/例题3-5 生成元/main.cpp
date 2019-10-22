#include <cstdio>
#include <cstring>

const int maxn = 100005;

int ans[maxn];

int main(int argc, const char **argv)
{
    int T, n;
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < maxn; ++i)
    {
        int x = i, y = i;
        while (x > 0)
        {
            y += x % 10;
            x /= 10;
        }
        if (y < maxn && ans[y] == 0)
            ans[y] = i;
    }
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
    return 0;
}