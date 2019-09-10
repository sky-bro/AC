/**
 *  求n以内的所有素数
 *  利用对于每个小于n的i，只用看3~sqrt(i)就好了
 *  这里的i当然从3开始，每次增加2
 */
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", 2);
    for (int i = 3; i <= n; i+=2){
        int j = 3;
        for (; j * j<= i; j += 2){
            if (i % j == 0)
                break;
        }
        if (j*j > i)
            printf("%d\n", i);
    }
    return 0;
}