#include <iostream>
using namespace std;

int main(int argc, const char** argv) {
    int N, NA, NB, sumA=0, sumB=0, tmp;
    cin>>N>>NA>>NB;
    int *a = new int[NA];
    int *b = new int[NB];
    for (int i = 0; i < NA; ++i) cin>>a[i];
    for (int i = 0; i < NB; ++i) cin>>b[i];
    for (int i = 0; i < N; ++i) {
        tmp = a[i%NA] - b[i%NB];
        if (tmp > 0 && tmp !=5 || tmp==-5) sumB++;
        else if (tmp != 0) sumA++;
    }
    if (sumA > sumB) {
        cout << "A" <<endl;
    } else if (sumA < sumB) {
        cout << "B" <<endl;
    } else {
        cout << "draw" <<endl;
    }
    delete [] a;
    delete [] b;
    return 0;
}