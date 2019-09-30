#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

char c[80];

int main(int argc, const char** argv) {
    cin.getline(c, 80);
    int len = strlen(c);
    // cout<<len<<endl;
    for (int i = 0; i < len; ++i) {
        if (islower(c[i])) {
            c[i] = toupper(c[i]);
        } else if (isupper(c[i])) {
            c[i] = tolower(c[i]);
        }
    }
    cout<<c<<endl;
    return 0;
}