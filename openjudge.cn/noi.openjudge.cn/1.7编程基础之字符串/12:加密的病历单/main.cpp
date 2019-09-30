#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
int main(int argc, const char** argv) {
    char c[50];
    cin>>c;
    int len = strlen(c);
    for (int i = 0;i < len; ++i) {
        if (islower(c[i])) {
            c[i] = (c[i] - 'a' + 3) % 26 + 'a';
            c[i] = toupper(c[i]);
        } else {
            c[i] = (c[i] - 'A' + 3) % 26 + 'A';
            c[i] = tolower(c[i]);
        }
    }

    for (int i = len-1; i >= 0; --i) {
        cout<<c[i];
    }
    cout<<endl;
    return 0;
}