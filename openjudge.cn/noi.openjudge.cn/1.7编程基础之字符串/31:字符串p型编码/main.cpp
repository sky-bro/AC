#include <iostream>
#include <cstring>

using namespace std;
char a[1001];
int main(int argc, const char** argv) {
    cin>>a;
    int len = strlen(a);
    int j = 0, i = 1;
    for (; i < len; ++i) {
        if (a[i] != a[j]) {
            cout<<i-j<<a[j];
            j = i;
        }
    }
    cout<<i-j<<a[j]<<endl;
    return 0;
}