#include <iostream>

using namespace std;

int N;
int pos[100];

void NQueen(int n);

int main(){
    cin>>N;
    NQueen(0);
    return 0;
}

void NQueen(int n){
    if (n == N) {
        for (int i = 0; i < N; i ++ ){
            cout << pos[i] + 1 << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < N; ++i){
        int j = 0;
        for (; j < n; ++j){
            if (pos[j] == i || abs(pos[j] - i) == abs(n - j))
                break;
        }
        if (j == n){
            pos[n] = i;
            NQueen(n+1);
        }
    }
}