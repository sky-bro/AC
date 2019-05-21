#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    freopen("/home/sky-ubt/Coding/cpp/AC/playground/test/test01.txt", "r", stdin);
    int a, b;
    while(scanf("%d%d", &a, &b)==2){
        printf("%d\n", a+b);
    }
    return 0;
}