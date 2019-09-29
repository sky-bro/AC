#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, const char** argv) {
    char s[80];
    cin.getline(s, 80);
    size_t len = strlen(s);
    for (int i = 0; i < len; ++i) {
        if (s[i] == 'z' || s[i] == 'Z') s[i] -= 25;
        else if (s[i] < 'z' && s[i] >= 'a' || s[i] < 'Z' && s[i] >= 'A') s[i]++;
    }
    cout<<s<<endl;
    return 0;
}