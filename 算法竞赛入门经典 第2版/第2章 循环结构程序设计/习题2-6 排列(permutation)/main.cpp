#include <cstdio>
#include <cstring>

int main(int argc, char const *argv[])
{
    int cnt[10]{0};
    int x, y, z;
    for (int a = 1; a < 4; ++a)
    {
        for (int b = 1; b < 10; ++b)
        {
            if (a == b)
                continue;
            for (int c = 1; c < 10; ++c)
            {
                if (c == a || c == b)
                    continue;

                x = a * 100 + b * 10 + c;
                if (x > 330)
                    continue;
                cnt[a] = cnt[b] = cnt[c] = 1;
                y = x * 2;
                z = x * 3;
                while (y)
                {
                    if (cnt[y % 10])
                    {
                        break;
                    }
                    else
                    {
                        cnt[y % 10] = 1;
                    }
                    y /= 10;
                }
                while (z)
                {
                    if (cnt[z % 10])
                    {
                        break;
                    }
                    else
                    {
                        cnt[z % 10] = 1;
                    }
                    z /= 10;
                }
                if (!y && !z)
                {
                    printf("%d %d %d\n", x, 2 * x, 3 * x);
                }
                for (int i = 1; i < 10; ++i)
                    cnt[i] = 0;
            }
        }
    }
    return 0;
}
