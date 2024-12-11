#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int a, b, c;
    cin >> a >> b >> c;
    // (t + c) * b >= a*c
    int t = a * c / b - c;
    if ((t + c) * b < a * c)
    {
        ++t;
    }
    cout << t << endl;
    return 0;
}
