#include<stdio.h>
#include<iostream>
using namespace std;
string s,s1,s2;
int l1,l2;
int main(){
    cin>>s1>>s2;
    l1=s1.length();
    l2=s2.length();
    if(l1>l2){
        s=s1;s1=s2;s2=s;
    }
    l1=s1.length();
    l2=s2.length();
    s1=s1+s1;
    s2=s2+s2;
    for(int i=l1;i>=1;i--){//i表示要截取的长度
        for(int j=0;j<=l1;j++){
            s=s1.substr(j,i);
            if(s2.find(s)!=-1){
                cout<<s.length()<<endl;
                return 0;
            }
        }
    }
    cout<<0<<endl;
    return 0;
}