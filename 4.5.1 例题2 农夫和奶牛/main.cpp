/**
 * 农夫John建造了一座很长的畜栏，它包括N个隔间，这些小隔间的位置为。。。
 * C头牛每头分到一个隔间，求最大最近距离
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int max_mindis(int a[], int n, int c);
bool test_dis(int a[], int n, int c, int d);

int main(int argc, const char** argv) {
    int a[] = {2, 3, 5, 8};
    int n = sizeof a / sizeof(int);
    int c = 3;
    printf("max distance: %d\n", max_mindis(a, n, c));
    return 0;
}

int max_mindis(int a[], int n, int c){
    sort(a, a+n);
    int L = 0;
    int R = (a[n - 1] - a[0]) / (c - 1);
    int mid = L + (R - L) / 2;
    int result = -1;
    while (L <= R){
        if (test_dis(a, n, c, mid)) { result = mid; L = mid + 1;}
        else R = mid - 1;
        mid = L + (R - L) / 2;
    }
    return result;
}

bool test_dis(int a[], int n, int c, int d){
    // 一头一头地放
    int j = 0;
    int last_x = a[0];
    for (int i = 1; i < c; ++i){
        while (j < n && a[j] - last_x < d) ++j;
        if (j == n) return false;
        last_x = a[j];
    }
    return true;
}