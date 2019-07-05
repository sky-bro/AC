/**
 * n个数算24，必有两个数先算
 * 枚举这两个数
 * 枚举这两个数之间的运算
 * 1一数算24直接算（注意：浮点数比较不能用==）
 */

#include <iostream>
#include <cmath>

#define EPS 1e-2

using namespace std;

bool isZero(double a){
    return abs(a) <= EPS;
}

bool count24(int num[], int n){
    if (n == 1){
        return isZero(num[0] - 24);
    }
    int new_num[n];
    for (int i = 0; i < n-1; ++i){
        for (int j = i+1; j < n; ++j){
            int k = 0;
            for (int l = 0; l < n; ++l){
                if (l!=i && l!=j)
                    new_num[k++] = num[l];
            }
            new_num[k] = num[i] + num[j];
            if (count24(new_num, n-1)) return true;

            new_num[k] = num[i] - num[j];
            if (count24(new_num, n-1)) return true;
            new_num[k] = num[j] - num[i];

            if (count24(new_num, n-1)) return true;
            new_num[k] = num[i] * num[j];
            if (count24(new_num, n-1)) return true;

            if (!isZero(num[j])){
                new_num[k] = num[i] / num[j];
                if (count24(new_num, n-1)) return true;
            }

            if (!isZero(num[i])){
                new_num[k] = num[j] / num[i];
                if (count24(new_num, n-1)) return true;
            }

            return false;
            
        }
    }
}

int main(int argc, const char** argv) {
    int n;
    cin>>n;
    int num[4];
    for (int i = 0; i < n; ++i)
    {
        cin>>num[0]>>num[1]>>num[2]>>num[3];
        bool result = count24(num, 4)?true:false;
        cout<<result<<endl;
    }
    
    return 0;
}