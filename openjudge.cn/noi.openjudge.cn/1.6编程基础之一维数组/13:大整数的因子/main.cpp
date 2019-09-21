// 8ms
#include <iostream>
#include <cstring>

using namespace std;

// 被除数、因子个数
int a[201],k=0;
// 字符串读入数字n
char s[201];
int main() {
    cin>>s;
    a[0]=strlen(s);
    // 将数字n从s中的字符形式转换为整数int形式
    for(int i=1; i<=a[0]; i++) {
        a[i]=s[i-1]-'0';
    }
    int t;
    for(int q=2; q<=9; q++) {
        // 余数
        t=0;
        // 模拟除法运算，从高位到低位，但只保留了余数
        for(int i=1; i<=a[0]; i++) {
            t=t*10+a[i];
            t%=q;
        }
        // 余数为0，说明除数q是因子
        if(t==0) {
            cout<<q<<" ";
            // 累加因子个数
            k++;
        }
    }
    // 0个因子
    if(k==0)cout<<"none";
    cout<<endl;
    return 0;
    //官方答案（重置）
}