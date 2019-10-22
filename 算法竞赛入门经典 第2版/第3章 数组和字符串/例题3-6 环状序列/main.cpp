#include <cstdio>
#include <cstring>

const int maxn = 105;

bool less(const char *s, int p, int q)
{
    int n = strlen(s);
    for (int i = 0; i < n; ++i)
    {
        if (s[(p + i) % n] != s[(q + i) % n])
            return s[(p + i) % n] < s[(q + i) % n];
    }
    return false;
}

int main(int argc, const char **argv)
{
    int T;
    char s[maxn];
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s);
        int ans = 0;
        int n = strlen(s);
        for (int i = 0; i < n; ++i)
        {
            if (less(s, i, ans))
                ans = i;
        }
        for (int i = 0; i < n; ++i)
        {
            putchar(s[(i + ans) % n]);
        }
        putchar('\n');
    }
    return 0;
}