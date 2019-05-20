#include <iostream>
#include <cstdio>
using namespace std;

#define ESP 0.001

int main(){
    unsigned long long a;
    printf("please input number a to compute root for:\n");
    scanf("%llu", &a);
    double a_half = (double)a/2;
    double x_cur = a/2, x_prev;
    do {
        x_prev = x_cur;
        x_cur = x_prev/2 + a_half/x_prev;
    } while (x_prev-x_cur > ESP || x_cur - x_prev > ESP);
    printf("root for %llu is %.3f\n", a, x_cur);
    return 0;
}