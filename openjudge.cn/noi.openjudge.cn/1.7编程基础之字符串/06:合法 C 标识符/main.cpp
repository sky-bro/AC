#include <iostream>

using namespace std;

int main(int argc, const char** argv) {
    string s;
    cin>>s;
    size_t len = s.length();
    if (s[0] <= '9' && s[0] >= '0' ) {
        cout<<"no"<<endl;
        return 0;
    }
    int i = 0;
    for (; i < s.length(); ++i) {
        // cout<<"s[i] "<<s[i]<<endl;
        if (!(s[i] <= '9' && s[i] >= '0' 
        || s[i] == '_'
        || s[i] >= 'A' && s[i] <= 'Z' 
        || s[i] >= 'a' && s[i] <= 'z')) {
            // 如果不是数字字母下划线就肯定不是合法的标识符
            break;
        }
    }
    if (i == len) {
        cout<<"yes" <<endl;
    } else {
        cout<<"no"<<endl;
    }
    return 0;
}