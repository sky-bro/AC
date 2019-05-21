#include <iostream>
#include <cstdio>
using namespace std;
int monthDays[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
    int y, m, d, days = 0;
    cin >> y >> m >> d;
    for (int year = 2012; year < y; ++year)
    {
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
            days += 366;
        else
            days += 365;
    }
    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
        monthDays[2] = 29;
    for (int i = 1; i < m; ++i)
        days += monthDays[i];
    days += d;
    days -= 22;
    cout << days % 7 << endl;
    return 0;
}