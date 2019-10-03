#include <iostream>
#include <cstring>

using namespace std;

char c[101];

int main(int argc, const char** argv) {
    cin>>c;
    int len = strlen(c);
    for (int i = 0, j = len-1; i < j; ++i, --j) {
        if (c[i] != c[j]) {
            cout<<"no"<<endl;
            return 0;
        }
    }
    cout<<"yes"<<endl;
    return 0;
}