#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
char a[80];
char b[80];
int main(int argc, const char** argv) {
    cin.getline(a, 80).getline(b, 80);
    int len1 = strlen(a), len2 = strlen(b);
    len1 = len1 <= len2?len1:len2;
    for (int i = 0; i <= len1; ++i) {
        a[i] = tolower(a[i]);
        b[i] = tolower(b[i]);
        if (a[i] < b[i]) {
            cout<<"<"<<endl;
            return 0;
        } else if (a[i] > b[i]) {
            cout<<">"<<endl;
            return 0;
        }
    }
    cout<<"="<<endl;
    return 0;
}