#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

char c[1001];

int main(int argc, const char** argv) {
    cin>>c;
    int len = strlen(c);
    int i = 0, j = 1;
    for ( ; j < len; ) {
        c[i] = toupper(c[i]);
        for (j = i+1 ; j < len; ++j) {
            if (c[j] != c[i] && c[j] - 'a' + 'A' != c[i]) {
                printf("(%c,%d)", c[i], j-i);
                i = j;
                break;
            }
        }
    }
    printf("(%c,%d)\n", c[i], j-i);
    return 0;
}