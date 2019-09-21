#include<bits/stdc++.h>
#define MAXX (99999)
using namespace std;
#define rda(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);
#define srd(); fclose(stdin);fclose(stdout);
int a[201],b,c[202]= {0},k=0;
char s[201];
int main() {
    // 没必要？静态变量初始化为全0
    for(int i=1; i<=201; i++) {
        a[i]=0;
    }
    cin>>s;
    a[0]=strlen(s);
    for(int i=1; i<=a[0]; i++) {
        a[i]=s[i-1]-'0';
    }
    int t;
    for(int q=2; q<=9; q++) {
        // 余数
        t=0;
        // 除数（没有改变q，，干嘛还赋值给b。。）
        b=q;
        // 模拟除法运算，从高位到低位，但只保留了余数
        for(int i=1; i<=a[0]; i++) {
            t=t*10+a[i];
            t%=b;
        }
        // 余数为0，说明除数b是因子
        if(t==0) {
            cout<<b<<" ";
            // 累加因子个数
            k++;
        }
    }
    // 0个因子
    if(k==0)cout<<"none"
    srd();
    return 0;
    //官方答案
}