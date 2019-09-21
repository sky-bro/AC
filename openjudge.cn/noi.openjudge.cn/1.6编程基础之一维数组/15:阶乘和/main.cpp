#include <iostream>
using namespace std;

// fac[0]记录阶乘结果的位数
int fac[100] = {1, 1};
// sum[0]记录求和结果的位数
int sum[100] = {1, 1};


int main(int argc, const char** argv) {
    int n; cin>>n;
    int x=0; // 临时保存运算中的进位
    for (int i = 2; i <= n; ++i) { // 计算i的阶乘并加到sum（通过把i和累积的fac相乘得到当前的i的阶乘）

        // 1. 计算i! (这里循环得用j，下面循环用i倒没事，刚开始统统i。。)
        for (int j = 1; j <= fac[0]; ++j) { // 一位一位乘
            fac[j] = fac[j] * i + x; // 因为这里i是用来乘的
            x = 0;
            if (fac[j] >= 10) {
                if (fac[0] == j) fac[0]++;
                x  = fac[j]/10;
                fac[j] = fac[j]%10;
            }
        }

        // 输出fac
        // for (int i = fac[0]; i > 0; --i)
        //     cout<<fac[i];
        // cout<<endl;

        // 2. sum加上i!
        if (fac[0] > sum[0]) sum[0] = fac[0]; // 此次累加sum位数至少是两者中大的一个
        for (int i = 1; i <= sum[0]; ++i) { // 一位一位加
            sum[i] += fac[i] + x;
            x = 0;
            if (sum[i] >= 10) {
                if (sum[0] == i) sum[0]++;
                x = 1;
                sum[i] = sum[i]%10;
            }
        }

    }
    // 输出sum
    for (int i = sum[0]; i > 0; --i)
        cout<<sum[i];
    cout<<endl;
    return 0;
}