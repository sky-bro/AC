// 百练 2757:最长上升子序列
#include <iostream>

using namespace std;

// 求最长子序列
int LSS(int a[], int n){
    int *b = new int[n];
    for (int i = 0; i < n; ++i){
        b[i] = 1;
    }
    for (int i = 1; i < n; ++i){
        for (int j = i-1; j >= 0; --j){
            if (j + 1 < b[i]) break;
            if (a[j] < a[i]){
                if (b[j] + 1 > b[i]) {
                    b[i] = b[j] + 1;
                }
            }
        }
    }
    int result = 1;
    for (int i = n-1; i >= 1; --i) {
        if (i + 1 < result) break;
        if (b[i] > result) result = b[i];
    }
    delete [] b;
    return result;
}

int main(int argc, char const *argv[])
{
    int n; cin>>n;
    int *a = new int[n];
    for (int i = 0; i < n; ++i){
        cin>>a[i];
    }
    cout<<LSS(a, n)<<endl;
    delete [] a;
    return 0;
}
