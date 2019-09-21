#include <iostream>
#include <cstring>

using namespace std;

char a[101];

int main(int argc, const char** argv) {
    // 注意这里不能直接cin，反正试过了会错，应该是有space？默认cin>>会跳过一些啥？字符
    cin.getline(a, 101);
    int len = strlen(a);
    char c = a[0];
    int i = 0;
    for (; i < len-1; ++i) {
        a[i] += a[i+1];
    }
    a[i] += c;
    cout<<a<<endl;
    return 0;
}