#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

char s[101];
char a[101];
char b[101];

int main(int argc, const char** argv) {
    vector<string> v;
    string str; char *p;
    cin.getline(s, 101)
        .getline(a, 101)
        .getline(b, 101);
    p = strtok(s, " ");
    while (p) {
        if (!strcmp(a, p)) str = b;
        else str = p;
        // cout<<str<<endl;
        v.push_back(str);
        p = strtok(nullptr, " ");
    }
    for (int i = 0; i < v.size()-1; ++i) {
        cout<<v[i]<<" ";
    }
    cout<<v[v.size()-1]<<endl;
    return 0;
}