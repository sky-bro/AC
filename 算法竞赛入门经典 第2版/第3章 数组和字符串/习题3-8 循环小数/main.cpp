#include <iostream>
using namespace std;

// 被除数是否出现过
int tmp[3001];
// 小数部分
int decimal[3001];

int main(int argc, const char **argv)
{
    int a, b, cnt = 0;
    cin >> a >> b;
    // 整数部分x
    int x = a / b;
    a %= b;
    a *= 10;
    while (tmp[a] == 0) // 被除数a之前没出现过
    {
        ++cnt;
        tmp[a] = cnt;
        decimal[cnt] = a / b;
        a %= b;
        a *= 10;
    }
    cout << cnt - tmp[a] + 1 << endl;
    cout << x;

    cout << ".";
    for (int i = 1; i < tmp[a]; ++i)
    {
        cout << decimal[i];
    }
    cout << "(";
    for (int i = tmp[a]; i <= cnt; ++i)
    {
        cout << decimal[i];
    }
    cout << ")\n";
    return 0;
}