#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, const char **argv)
{
    int m, n;
    for (int i = 1; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            m = i * 1100 + j * 11;
            n = floor(sqrt(m));
            if (n * n == m)
            {
                cout << m << " " << n << endl;
            }
        }
    }
    return 0;
}