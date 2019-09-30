#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;
char c[101];
int main(int argc, const char** argv) {
    cin.getline(c, 101);
    int len = strlen(c);
    for (int i = 0; i < len; ++i) {
        if (islower(c[i])) {
            c[i] = toupper(c[i]);
        }
    }
    cout<<c<<endl;
    return 0;
}