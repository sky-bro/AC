#include <iostream>
#include <cstring>

using namespace std;

char a[501];
char b[501];

int main(int argc, const char** argv) {
    double threshold;
    cin>>threshold>>a>>b;
    int len = strlen(a), cnt=0;
    for (int i = 0; i < len; ++i) if (a[i]==b[i]) cnt++;
    if (len*threshold > cnt) { // 不相关
        cout<<"no"<<endl;
    } else { // 相关
        cout<<"yes"<<endl;
    }
    return 0;
}