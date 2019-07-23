#include <iostream>

using namespace std;

int merge(int a[], int s, int mid, int e, int b[]){
    int k = s, sum = 0;
    int i = s, j = mid + 1;
    while (i != mid + 1 && j != e + 1){
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
            sum += (mid - i + 1);
        }
    }
    while (i <= mid) b[k++] = a[i++];
    i = s;
    while (i != j) a[i++] = b[i];
    return sum;
}

int mergeSortAndCount(int a[], int s, int e, int b[]){
    if (s >= e) return 0;
    int sum = 0;
    int mid = s + (e-s)/2;
    sum += mergeSortAndCount(a, s, mid, b);
    sum += mergeSortAndCount(a, mid + 1, e, b);
    sum += merge(a, s, mid, e, b);
    return sum;
}

void printArr(int a[], int n){
    for (int i = 0; i < n; ++ i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    int a[] = {5, 4, 3, 2, 1};
    int n = sizeof a / sizeof(int);
    int *b = new int[n];
    printArr(a, n);
    cout<<mergeSortAndCount(a, 0, n-1, b)<<endl;
    printArr(a, n);
    delete [] b;
    return 0;
}