#include <iostream>
#include <cstring>

using namespace std;

char c[501];

int main(int argc, const char** argv) {
    cin.getline(c, 501);
    int len = strlen(c);
    int w_begin = 0;
    for (int i = 0; i < len;) {
        if (c[i] == ' ') {
            cout<<" ";
            i++;
            continue;
        }
        int j = i + 1;
        for (; j < len && c[j] != ' '; ++j);
        for (int k = j-1; k >= i; --k) {
            cout<<c[k];
        }
        i = j;
    }
    return 0;
}