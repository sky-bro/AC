#include <iostream>
#include <algorithm>

using namespace std;

// get
void arrangeRight(int a[], int s, int e, int k){
    int r;
    while (true){
        int mid = a[s];
        r = partition(a+s, a+e+1, [mid](int x){return x<mid;}) - a;
        int i = e-k+1+s;
        if (r < i){
            s = r + 1;
        } else if (r > i){
            k = r-i;
            e = r - 1;
        } else {
            return;
        }
    }
    
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
    arrangeRight(a, 0, n - 1, 3);
    printArr(a+(n-3), 3);
    return 0;
}
