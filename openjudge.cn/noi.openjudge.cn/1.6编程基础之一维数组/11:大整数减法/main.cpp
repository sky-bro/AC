#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char** argv) {
    string a, b;
    int c[200] = {0};
    cin>>a>>b;
    int lenA = a.length();
    int lenB = b.length();
    for (int i = 0; i < lenB; ++i) {
        c[i] += a[lenA-i-1] - b[lenB-i-1];
        if (c[i] < 0) {
            c[i] += 10;
            c[i+1] -= 1;
        }
    }

    for (int i = lenB; i < lenA; ++i) {
        c[i] += a[lenA-i-1]-'0';
        if (c[i] < 0) {
            c[i] += 10;
            c[i+1] -= 1;
        }
    }
    int t = 199;
    for (; c[t]==0; --t);
    for (; t>=0; --t) {
        cout<<c[t];
    }
    cout<<endl;
    return 0;
}