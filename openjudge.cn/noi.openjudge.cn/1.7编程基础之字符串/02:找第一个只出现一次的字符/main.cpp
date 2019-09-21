#include <iostream>
#include <cstring>

using namespace std;
char c[100000];
int cnt[26]; // 字母出现次数
int ordinal[26]; // 字母出现顺序
int main(int argc, const char** argv) {
    cin>>c;
    int len = strlen(c);
    int ind, // 字母转换为序号，a对应0，z对应25
        ord=1; // 字母出现次序
    for (int i = 0; i < len; ++i) {
        ind = c[i] - 'a';
        cnt[ind]++;
        if (!ordinal[ind]) {
            ordinal[ind] = ord++;
        }
    }

    // 寻找第一个出现的且仅出现一次的字符
    int pre_ord = 27; char result;
    for (int i = 0; i < 26; ++i) {
        if (ordinal[i] > 0 && ordinal[i] < pre_ord && cnt[i] == 1) {
            pre_ord = ordinal[i];
            result = 'a' + i;
        }
    }
    if (pre_ord == 27) {
        cout<<"no"<<endl;
    } else {
        cout<<result<<endl;
    }
    return 0;
}

// abasdfasfjasldfjaslgjalsdfjasldfhahl