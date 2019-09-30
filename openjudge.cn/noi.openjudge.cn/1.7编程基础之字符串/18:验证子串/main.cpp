#include <iostream>

using namespace std;

int main(int argc, const char** argv) {
    string s1,s2;
    cin>>s1>>s2;
    if (s1.find(s2)!=string::npos) cout<<s2<<" is substring of "<<s1;
    else if (s2.find(s1)!=string::npos) cout<<s1<<" is substring of "<<s2;
    else cout<<"No substring";
    return 0;
}