#include <iostream>
#include <cmath>
#include <cstdio>

#define EPS 1e-6

double f(double x) { return x*x*x - 5*x*x + 10*x - 80; }

int main(int argc, const char** argv) {
    double root,
        x1 = 0,
        x2 = 100,
        y;
    int tried_times = 1;
    root = x1 + (x2 - x1) / 2;
    y = f(root);
    while (fabs(y) > EPS){
        if (y > 0) x2 = root;
        else x1 = root;
        root = x1 + (x2 - x1) / 2;
        y = f(root);
        ++tried_times;
    }
    printf("%.8f\n", root);
    printf("%d\n", tried_times);
    return 0;
}