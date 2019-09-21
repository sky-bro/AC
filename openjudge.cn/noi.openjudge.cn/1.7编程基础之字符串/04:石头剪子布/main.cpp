#include <iostream>

using namespace std;

char a[10];
char b[10];

int main(int argc, const char** argv) {
    int n, tmp;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>a>>b;
        // P R S
        // PQRS
        // +2 +1
        tmp = a[0] - b[0];
        if (tmp > 0 && tmp != 3 || tmp == -3) {// a输
            cout<<"Player2"<<endl;
        } else if (!tmp){
            cout<<"Tie"<<endl;
        } else {
            cout<<"Player1"<<endl;
        }
    }
    return 0;
}