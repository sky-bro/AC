#include <iostream>
using namespace std;

int main(int argc, const char** argv) {
    string s;
    cin>>s;
    size_t len = s.length();
    for (int i = 0; i < len; ++i) {
        switch (s[i])
        {
        case 'A':
            cout<<'T';
            break;
        case 'T':
            cout<<'A';
            break;
        case 'C':
            cout<<'G';
            break;
        case 'G':
            cout<<'C';
        }
    }
    cout<<endl;
    return 0;
}
