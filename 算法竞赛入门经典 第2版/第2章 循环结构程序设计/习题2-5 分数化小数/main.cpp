#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, const char **argv)
{
    int a, b, c, kase = 0;
    while (cin >> a >> b >> c && !(a == 0 && b == 0 && c == 0))
    {
        printf("Case %d: ", ++kase);
        cout << setprecision(c) << 1.0 * a / b << endl;
    }
    return 0;
}