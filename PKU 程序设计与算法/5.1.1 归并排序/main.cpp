#include <iostream>

using namespace std;

void merge(int a[], int p, int q, int r, int b[]);
void merge_sort(int a[], int p, int q, int b[]);

void print_arr(int a[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(int argc, const char** argv) {
    int a[] = {5, 4, 3, 2, 1};
    int b[5];
    printf("before sort\n");
    print_arr(a, 5);
    merge_sort(a, 0, 4, b);
    printf("after sort\n");
    print_arr(a, 5);
    return 0;
}

void merge(int a[], int p, int q, int r, int b[]){
    int ib = 0;
    int i = p, j = q + 1;
    while (i <= q && j <= r){
        if (a[i] < a[j]) b[ib++] = a[i++];
        else b[ib++] = a[j++];
    }

    while (i <= q) b[ib++] = a[i++];
    while (j <= r) b[ib++] = a[j++];

    ib = 0;
    for (int i = p; i <= r; ++i){
        a[i] = b[ib++];
    }
}

void merge_sort(int a[], int p, int q, int b[]) {
    if (p < q) {
        int m = p + (q - p) / 2;
        merge_sort(a, p, m, b);
        merge_sort(a, m + 1, q, b);
        merge(a, p, m, q, b);
    }
}