#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j; --j)
            printf(" ");
        for (int j = 0; j < 2 * (n - i) - 1; ++j)
            printf("#");
        printf("\n");
    }
    return 0;
}
