#include <iostream>
#include <cstring>
using namespace std;
char c[1001];
int main(int argc, const char** argv) {
    cin>>c;
    cout<<strlen(c);
    while (cin>>c){
        cout<<","<<strlen(c);
    }
    cout<<endl;
    return 0;
}