#include <iostream>
using namespace std;

int main(int argc, const char **argv)
{
    long long n, cnt = 0;
    cin >> n;
    while (n > 1)
    {
        ++cnt;
        if (n & 1)
        {
            n = 3 * n + 1;
        }
        else
        {
            n >>= 1;
        }
    }

    cout << cnt << endl;
    return 0;
}