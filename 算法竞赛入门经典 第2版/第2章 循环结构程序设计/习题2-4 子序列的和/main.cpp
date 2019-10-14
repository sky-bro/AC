#include <iostream>
using namespace std;

int main(int argc, const char **argv)
{
    int n, m, kase = 0;
    double sum;
    while (cin >> n >> m && m != 0)
    {
        sum = 0.0;
        for (int i = n; i <= m; ++i)
        {
            sum += 1.0 / i / i;
        }
        printf("Case %d: %.5f\n", ++kase, sum);
    }
    return 0;
}