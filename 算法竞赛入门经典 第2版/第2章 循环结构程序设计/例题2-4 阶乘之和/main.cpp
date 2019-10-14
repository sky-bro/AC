#include <iostream>
using namespace std;

const int MOD = 1000000;

int main(int argc, const char **argv)
{
    long long n;
    cin >> n;
    int a = 0, b = 1;
    for (int i = 1; i <= n; ++i)
    {
        b = (b * i) % MOD;
        a = (a + b) % MOD;
    }
    cout << a << endl;
    return 0;
}