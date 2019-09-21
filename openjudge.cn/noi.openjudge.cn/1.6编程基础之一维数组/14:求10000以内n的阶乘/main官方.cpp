// 没看懂
#include <cstdio>
#include <cstring>
using namespace std;
int a[500000]={1, 1}, c[50000];

void clean(int x[]){
    while(x[x[0]]==0 && x[0]>1)
        x[0]--;
}

void xc(int x[], int j){
    x[0]+=10;
    for(int i=1; i<=x[0]; i++){
        x[i]*=j;
    }
    for(int i=1; i<=x[0]; i++){
        x[i+1]+=x[i]/10;
        x[i]%=10;
    }
    clean(x);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int j=2; j<=n; j++){
        xc(a, j);
    }
    for(int i=a[0]; i>0; i--)
        printf("%d", a[i]);
    return 0;
    //官方答案
}