#include <iostream>
#include <cstring>

using namespace std;
char s[210];
int main(int argc, const char** argv) {
    cin.getline(s, 210);
    size_t len = strlen(s);
    for (int i = 0; i < len; ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = (s[i] - 'A' + 21) % 26 + 'A';
        }
    }
    cout<<s<<endl;
    return 0;
}