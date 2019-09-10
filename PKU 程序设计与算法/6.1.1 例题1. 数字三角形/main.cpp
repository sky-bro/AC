// 可以一行一行，一边读一边算，到最后一排，多遍历一遍求最大值

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int* a = new int[n];
    int* b = new int[n];    
    cin>>a[0];
    for (int i = 1; i < n; ++i){
        for (int j = 0; j <= i; ++j){
            cin>>b[j];
        }
        a[i] = a[i-1] + b[i];
        for (int j = i - 1; j > 0; --j) {
            if (a[j] > a[j-1]){
                a[j] = b[j] + a[j];
            } else {
                a[j] = b[j] + a[j-1];
            }
        }
        a[0] = a[0] + b[0];
    }
    cout<<*max_element(a, a+n)<<endl;
    delete [] a;
    delete [] b;
    return 0;
}

