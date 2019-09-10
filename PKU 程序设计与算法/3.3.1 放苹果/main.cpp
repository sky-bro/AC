/**
 * i个苹果放到k个盘子里面，放法总数f(i, k)
 *  k>i: =f(i,i)
 *  k<=i: =f(i, k-1) + f(i-k, k)
 *  i==0: 1
 *  k==0: 0
 */

#include <iostream>

#define M 10

int results[M][M];

using namespace std;

int f(int m, int n){
    if (n > m) return f(m, m);
    if (m == 0) return 1;
    if (n == 0) return 0;
    int r = f(m, n-1) + f(m-n, n);
    results[m][n] = r;
    return r;

}

int main(int argc, const char** argv) {
    for (int i = 0; i<M;++i){
        for (int j = 0; j < M; ++j)
            results[i][j] = -1;
    }
    int cnt, m, n;
    cin>>cnt;
    for (int i =0; i<cnt && cin>>m>>n; ++i){
        cout<<f(m,n)<<endl;
    }
    return 0;
}