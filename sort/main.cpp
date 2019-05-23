#include <iostream>
#include <cstdio>
#include <unistd.h>
#include "sort.h"
using namespace std;

void printArr(int a[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int a[100];

int main()
{
    // freopen("../../test/test01.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    printf("%d\n", n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", a + i);
    }

    printf("before sort:\n");
    printArr(a, n);

    printf("after selection sort:\n");
    selection_sort(a, n);
    printArr(a, n);

    printf("after bubble sort\n");
    bubble_sort(a, n);
    printArr(a, n);

    return 0;
}