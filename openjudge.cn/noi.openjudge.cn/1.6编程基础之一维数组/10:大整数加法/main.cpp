// wrong
#include <iostream>
#include <cstring>
using namespace std;


int main(int argc, const char** argv) {
    char *a = new char[202];
    char *b = new char[202];
    cin>>a+1>>b+1;
    // cout<<a+1<<endl;
    // cout<<b+1<<endl;
    int lenA = strlen(a+1);
    int lenB = strlen(b+1);
    if (lenA>lenB) {
        int itmp = lenA; lenA = lenB; lenB = itmp;
        char *pctmp = a; a = b; b = pctmp;
    }
    b[0] = '0';
    for (int i = 0; i < lenA; ++i) {
        b[lenB-i] += a[lenA-i]-'0'-'0';
        b[lenB-i-1] += b[lenB-i]/10;
        b[lenB-i] = b[lenB-i]%10+'0';
        // cout<<b+lenB-i<<endl;
    }
    for (int i = lenB-lenA; i > 0; --i) {
        if (b[i] >= 10+'0') {
            b[i] -= 10;
            b[i-1] += 1;
        } else break;
    }
    int i = 0;
    for (; b[i]=='0'; ++i);
    cout<<b+i<<endl;
    return 0;
}