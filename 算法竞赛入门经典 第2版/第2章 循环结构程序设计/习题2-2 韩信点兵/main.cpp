#include <iostream>

using namespace std;

int main(int argc, const char **argv)
{
    int a, b, c, kase = 0, n;
    while (cin >> a >> b >> c)
    {
        for (n = 10; n % 3 != a; ++n)
            ;
        for (; n % 5 != b; n += 3)
            ;
        for (; n < 101 && n % 7 != c; n += 15)
            ;

        printf("Case %d: ", ++kase);
        if (n < 101)
        {
            printf("%d\n", n);
        }
        else
        {
            printf("No answer");
        }
    }
    return 0;
}