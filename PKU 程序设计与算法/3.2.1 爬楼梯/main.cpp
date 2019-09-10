#include <iostream>

#define N 50

using namespace std;

int result[N];

int stairs(int n){
    if (n == 1 || n == 0){
        return 1;
    }
    if (result[n] != -1){
        return result[n];
    }
    result[n] = stairs(n-1) + stairs(n-2);
    return result[n];
}

int main(int argc, const char** argv) {
    for (int i = 0; i < N; ++i){
        result[i] = -1;
    }
    int n;
    while (cin>>n){
        cout<<stairs(n)<<endl;
    }

    return 0;
}