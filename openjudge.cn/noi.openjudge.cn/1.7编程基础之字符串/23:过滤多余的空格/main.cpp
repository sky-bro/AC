#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

char c[201], *p;

int main(int argc, const char** argv) {
    cin.getline(c, 201);
    vector<string> v;
    p = strtok(c, " ");
    while (p) {
        v.push_back(p);
        p = strtok(nullptr, " ");
    }
    for (int i = 0; i < v.size()-1; ++i) {
        cout<<v[i]<<" ";
    }
    cout<<v[v.size()-1]<<endl;
    return 0;
}