#include <iostream>
#include <algorithm>

using namespace std;

void qsort(int a[], int s, int e){
    int i = s, j = e;
    if (i >= j) return;
    // partition
    int mid = a[i];
    // while (i != j){
    //     while (j > i && a[j] >= mid) --j;
    //     swap(a[i], a[j]);
    //     while (j > i && a[i] <= mid) ++i;
    // }
    // 也可以直接调用函数
    i = partition(a+s, a+e+1, [mid](int p) {return p < mid;}) - a;

    qsort(a, s, i-1);
    qsort(a, i+1, e);
}

void printArr(int a[], int n){
    for (int i = 0; i < n; ++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    int a[] = {5,4,3,2,1};
    int n = sizeof a / sizeof(int);
    qsort(a, 0, n-1);
    printArr(a, n);
    return 0;
}
