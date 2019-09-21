#include<iostream>
#include<cstring>
using namespace std;
int ans[100000],sum[100000];
int main()
{
    int n,i,j,k,len,lens=1,jin;
    cin>>n;
    for(k=1;k<=n;k++)
    {
        len=1;
        jin=0;
        memset(ans,0,sizeof(ans));
        ans[1]=1;
        for(i=1;i<=k;i++)
        {
            for(j=1;j<=len*2;j++)
            {
                ans[j]=ans[j]*i+jin;
                jin=ans[j]/10;
                ans[j]%=10;
            }
            while(ans[len+1]!=0)
                len++;
        }

        for(i=1;i<=lens+100;i++)
            sum[i]+=ans[i];

        for(i=1;i<=lens+100;i++)
        {
            if(sum[i]>=10)
            {
                sum[i]-=10;
                sum[i+1]++;
            }
        }
        while(sum[lens+1]!=0)
            lens++;
    }
    for(i=lens;i>=1;i--)
        cout<<sum[i];
    return 0;
    //官方答案
}