/**
 * 完美立方
 * a^3 = b^3 + c^3 + d^3
 * a: [2, n]
 * b: [2, a-1]
 * c: [b, a-1]
 * d: [c, a-1]
 */
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int a = 2; a <= n; ++a)
    {
        for (int b = 2; b <= a - 1; ++b)
        {
            for (int c = b; c <= a - 1; ++c)
            {
                for (int d = c; d <= a - 1; ++d)
                {
                    if (a * a * a == b * b * b + c * c * c + d * d * d)
                    {
                        cout << "Cube = " << a << ", Triple = (" << b << ", " << c << ", " << d << ")\n";
                    }
                }
            }
        }
    }
    return 0;
}