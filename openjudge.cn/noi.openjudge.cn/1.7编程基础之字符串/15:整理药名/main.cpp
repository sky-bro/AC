#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

char c[21];

int main(int argc, const char** argv) {
    int n, len; cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>c;
        len = strlen(c);
        c[0] = toupper(c[0]);
        for (int i = 1; i < len; ++i) {
            c[i] = tolower(c[i]);
        }
        cout<<c<<endl;
    }
    return 0;
}