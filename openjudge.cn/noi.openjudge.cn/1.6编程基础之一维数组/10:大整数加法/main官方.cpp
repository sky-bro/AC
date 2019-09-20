#include <iostream>
#include <string>
#define REP(a, b, c) for (int a = b; a <= c; ++a)
#define REQ(a, b, c) for (int a = b; a >= c; --a)
#define MAXN 207
using namespace std;
int t, a[MAXN], b[MAXN], c[MAXN];
string s1, s2;
int main()
{
    cin >> s1 >> s2;
    int siz1 = s1.size(), siz2 = s2.size();
    REP(i, 0, siz1 - 1) a[siz1 - i - 1] = s1[i] - '0';
    REP(i, 0, siz2 - 1) b[siz2 - i - 1] = s2[i] - '0';
    int siz = max(siz1, siz2);
    REP(i, 0, siz - 1)
    {
    c[i] += (a[i] + b[i]);
    if (c[i] >= 10) ++c[i + 1], c[i] -= 10;
    }
    REQ(i, siz, 0) if (c[i]) { t = i; break ; }
    REQ(i, t, 0) cout << c[i];
    cout << endl;
    return 0;
    //官方答案
}