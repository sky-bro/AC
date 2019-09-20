#include <iostream>
using namespace std;
int main(int argc, const char** argv) {
    int n, sum=0; cin>>n;
    int *A = new int[n];
    int *B = new int[n];
    for (int i = 0; i < n; ++i) cin>>A[i];
    for (int i = 0; i < n; ++i) cin>>B[i];
    for (int i = 0; i < n; ++i) {
        sum += A[i]*B[i];
    }
    cout<<sum<<endl;
    delete [] A;
    delete [] B;
    return 0;
}