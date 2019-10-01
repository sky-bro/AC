#include <iostream>
#include <cstring>

using namespace std;

int num[300];
char c[1001], *p;

int main(int argc, const char** argv) {
    cin.getline(c, 1001);
    p = strtok(c, " ");
    int n = 0;
    while (p) {
        num[n++] = strlen(p);
        p = strtok(nullptr, " ");
    }
    for (int i = 0; i < n-1; ++i) {
        cout<<num[i]<<",";
    }
    cout<<num[n-1]<<endl;
    return 0;
}