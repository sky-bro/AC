#include <iostream>

using namespace std;

int main(int argc, const char** argv) {
    string s1,s2;
    cin>>s1>>s2;
    if (s1.length() > s2.length()) {
        s1 = s1 + s1;
        if (s1.find(s2) != string::npos) cout<<"true"<<endl;
        else cout<<"false"<<endl;
    } else {
        s2 = s2 + s2;
        if (s2.find(s1) != string::npos) cout<<"true"<<endl;
        else cout<<"false"<<endl;
    }
    return 0;
}