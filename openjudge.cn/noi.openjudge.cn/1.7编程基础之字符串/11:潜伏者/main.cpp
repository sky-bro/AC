#include <iostream>
#include <cstring>

using namespace std;
int main(int argc, const char** argv) {
    string a, b;
    char c[101];
    cin>>a>>b>>c;
    int len1 = a.length(), len2 = strlen(c), ind1, ind2;
    char M[26] = {0}, N[26] = {0};
    if (len1 < 26) {
        cout<<"Failed"<<endl;
        return 0;
    }
    for (int i = 0; i < len1; ++i) {
        ind1 = a[i] - 'A';
        ind2 = b[i] - 'A';
        if (!M[ind1]) {
            M[ind1] = b[i];
            if (!N[ind2]) {
                N[ind2] = a[i];
            } else if (N[ind2] != a[i]) {
                cout<<"Failed"<<endl;
                return 0;
            }
        } else if (M[ind1] != b[i]) {
            cout<<"Failed"<<endl;
            return 0;
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (!M[i]) {
            cout<<"Failed"<<endl;
            return 0;
        }
    }
    for (int i = 0; i < len2; ++i) {
        c[i] = M[c[i]-'A'];
    }
    cout<<c<<endl;
    return 0;
}