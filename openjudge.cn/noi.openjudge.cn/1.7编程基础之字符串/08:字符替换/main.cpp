#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, const char** argv) {
    char s[31], a, b;

    cin>>s>>a>>b;
    size_t len = strlen(s);
    for (int i = 0; i < len; ++i) {
        if (s[i] == a) s[i] = b;
    }
    cout<<s<<endl;
    return 0;
}