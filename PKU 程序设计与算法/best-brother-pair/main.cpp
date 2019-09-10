/*
for given positive number a,
use newton's method to compute x,
so that x^2 = a;
*/
#include <iostream>
#include <cstdio>
using namespace std;

// control precision
#define ESP 0.001

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int a = m, b = m;
    for (int i = n; i < m; ++i)
    {
        if (i > (a + b) / 2)
            break;
        for (int j = i + 1; j <= m; ++j)
        {
            if (i + j > a + b)
                break;
            if (i * j % (i + j) == 0)
            {
                if ((i + j < a + b) || (i + j == a + b && i < a))
                {
                    a = i;
                    b = j;
                }
            }
        }
    }
    if (a == m){
        printf("No Solution");
    } else {
        printf("a = %d, b = %d\n", a, b);
    }
    return 0;
}