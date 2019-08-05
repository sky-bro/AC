#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int sum(int a, int b)
{
    return a + b;
}

int intCmp(const void *a, const void *b)
{
    int left = *((int *)a);
    int right = *((int *)b);
    return -left + right;
}

void test()
{
    static int a = 3;
    printf("%d", a);
    ++a;
}

void printArr(char a[], int n){
    for (int i =0; i< n; ++i){
        printf("%x ", a[i]);
    }
    printf("\n------------\n");
}

int main()
{
    // freopen("/home/sky-ubt/Coding/cpp/AC/playground/test/test01.txt", "r", stdin);
    int a[2];

    return 0;
}