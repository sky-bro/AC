#include <iostream>

using namespace std;

char c[16];

int main(int argc, const char** argv) {
    cin>>c;
    int cks = c[0]*1 + c[2]*2 + c[3]*3 + c[4]*4 +
        c[6]*5 + c[7]*6 + c[8]*7 + c[9]*8 + c[10]*9 - '0'*45;
    // cout<<cks<<endl;
    if ((cks %= 11) == 10) {
        cks = 'X';
    } else {
        cks += '0';
    }
    if (cks == c[12]) {
        cout<<"Right"<<endl;
    } else {
        c[12] = cks;
        cout<<c<<endl;
    }
    return 0;
}