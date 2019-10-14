// 计算pi/4

#include <iostream>
using namespace std;
const double eps = 1e-6;

int main(int argc, char const *argv[])
{
    double sum = 1;
    double term;
    for (int i = 1;; i++)
    {
        term = 1.0 / (i * 2 + 1);
        if (i & 1)
        {
            sum -= term;
        }
        else
        {
            sum += term;
        }
        if (term < eps)
            break;
    }
    cout << sum * 4 << endl;
    return 0;
}
