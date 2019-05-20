#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int a = 2.2;
    double b = 2.3;
    scanf("%d%lf", &a, &b);
    printf("%lu:%.1f", sizeof a, b);
    return 0;
}