#include <iostream>
#include <algorithm>

#define EPS 1e-6

double f(double x) { return x*x*x - 5*x*x + 10*x - 80; }

using namespace std;

int main(int argc, const char** argv) {
    int a[] = {3 , 2, 2, 5, 8, 1, 4, 6, 9, 7, 10, 0};
    int n = (sizeof a)/(sizeof(int));
    sort(a, a+n);
    int tmp;
    for (int i = 0, j = n - 1; i < j;) {
        tmp = a[i] + a[j];
        if (tmp == 10) { printf("%2d + %2d = %2d\n", a[i], a[j], 10); ++i; }
        else if (tmp < 10) ++i;
        else --j;
    }

    return 0;
}