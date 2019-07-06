#include <iostream>

using namespace std;

int binary_search(int a[], int n, int p);
int lower_bound(int a[], int n, int p);

int main(int argc, const char** argv) {
    int a[] = {1,1,2,2,3,3};
    cout<<binary_search(a, 6, 2)<<endl;
    cout<<lower_bound(a, 6, 2)<<endl;
    return 0;
}

int binary_search(int a[], int n, int p){
    int L = 0,
        R = n - 1,
        mid = L + (R - L) / 2;
    while (L <= R) {
        if (a[mid] == p) return mid;
        if (a[mid] > p) R = mid - 1;
        if (a[mid] < p) L = mid + 1;
        mid = L + (R - L) / 2;
    }
    // mid = R
    // L = R + 1
    return -mid;
}

// 值小于p的最大索引
int lower_bound(int a[], int n, int p){
    int L = 0,
        R = n - 1,
        mid = L + (R - L) / 2;
    int result = -1;
    while (L <= R) {
        if (a[mid] >= p) R = mid - 1;
        else {
            result = mid;
            L = mid + 1;
        }
        mid = L + (R - L) / 2;
    }
    return result;
}