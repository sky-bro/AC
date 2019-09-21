#include<bits/stdc++.h>//万能库
using namespace std;

int n,x=0,f[200000000],lf=1,t=0;//200000000是为了防止数据过大而溢出

int main(){

    f[1]=1;//1的阶乘可直接写出，省事

    cin>>n;

    for(int i=2;i<=n;i++){//1的阶乘已有，所以从2开始
        for(int j=1;j<=lf;j++){//每个数位都乘到

            f[j]=f[j]*i+x;//x是进位的数
            x=0;//刷新x的值

            if(f[j]>=10){//进位
                if(j==lf)lf++;//刷新数位
                x=f[j]/10;
                f[j]%=10;
            }
        }
    }
    
    // if(x>0){lf++;f[lf]=x;}//算完了可能还有进位，查缺补漏

    for(int i=lf;i>=1;i--)cout<<f[i];
    cout<<endl;

    return 0;
    // 同学答案
}