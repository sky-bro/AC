// ref: https://blog.csdn.net/qq_41357771/article/details/79896213
// 下面的实现是不带模的——对应leetcode 题可以用到这个方法求组合数，原文有带模的伪代码
#include <iostream>
#include <vector>

using namespace std;

vector<int> primes;

void make_p(int within_n){//挖素数
    vector<bool> vis(within_n+1);
    for(int i=2;i<=within_n;i++)
        if(!vis[i]){
            primes.push_back(i);
            for(int j=i*2; j<=within_n; j+=i) vis[j]=1;
        }
}
int qsm(int a,int b){//快速幂
    int ans=1,w=a;
    for(;b;b>>=1,w=(w*w)) if(b&1) ans=(ans*w);
    return ans;
}

int Get(int x,int y){//在x!中y这个因子出现的次数
    int sum=0;
    for(;x;x/=y) sum+=x/y;
    return sum;
}

int C(int x,int y){
    int ans=1;
    for(int p: primes){
        int T=Get(x,p)-Get(x-y,p)-Get(y,p);
        ans=(ans*qsm(p,T));
    } 
    return ans;
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin>>n;
    make_p(n);
    cout<<"123"<<endl;
    while (cin>>m) {
        cout<<"Num of Combinations: "<< C(n, m) <<endl;
    }
    return 0;
}
