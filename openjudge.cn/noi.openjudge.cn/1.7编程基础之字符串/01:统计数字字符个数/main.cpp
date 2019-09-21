#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, const char** argv) {
    char c[256];
    // getline中的256表示c最多能存256个字节数据，也就是说最多存放255个字符再加上'\0'
    cin.getline(c, 256);
    int len = strlen(c), cnt=0;
    // cout<<c<<len<<endl;
    for (int i = 0; i < len; ++i) {
        if (c[i] <= '9' && c[i] >= '0') cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}