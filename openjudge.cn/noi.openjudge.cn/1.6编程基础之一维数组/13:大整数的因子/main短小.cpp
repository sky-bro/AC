// 1ms
#include<bits/stdc++.h>
using namespace std;
string a;
int k,f,t,i;
main(){
cin>>a;
for(k=2;t=0,k<=9;k++){
for(i=0;i<a.size();i++)t=(t*10+a[i]-48)%k;
if(t==0)f=1,cout<<k<<" ";}
if(!f)cout<<"none";}