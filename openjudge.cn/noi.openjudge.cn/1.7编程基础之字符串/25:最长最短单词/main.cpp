#include <iostream>
#include <cstring>

using namespace std;
char tmp[101];
char s1[101];
char s2[101];
int main(int argc, const char** argv) {
    int max=0, min=101, len;
    while(cin>>tmp) {
        len = strlen(tmp);
        if (len > max) {strcpy(s1, tmp); max=len;}
        if (len < min) {strcpy(s2, tmp); min=len;}
    }
    cout<<s1<<endl;
    cout<<s2<<endl;
    return 0;
}