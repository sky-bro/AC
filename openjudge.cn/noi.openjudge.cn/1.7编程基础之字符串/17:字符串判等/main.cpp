#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main(int argc, const char** argv) {
    // string s; cin>>s; cout<<int(s[0])<<endl;
    char a, b;
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    int i = 0, j = 0, len1 = str1.length(), len2 = str2.length();
    for (; i < len1 && j < len2; ++i, ++j ) {
        while (isspace(str1[i])) i++;
        while (isspace(str2[j])) j++;
        a = tolower(str1[i]);
        b = tolower(str2[j]);
        if (a != b) {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}