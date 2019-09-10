// 筛法求素数
#include <iostream>
#include <cstdio>
using namespace std;
#define N 10
bool isPrime[N + 10];
int main()
{
    for (int i = 2; i <= N; ++i)
        isPrime[i] = true;
    for (int i = 2; i <= N; ++i)
    {
        if (isPrime[i])
            for (int j = 2 * i; j <= N; j += i)
                isPrime[j] = false;
    }
    for (int i = 2; i <= N; ++i)
        if (isPrime[i])
            cout << i << endl;
    return 0;
}