// 这里注意c和python的区别
// python: -1 = -10 + 9, -1 / 10 = -1, -1 % 10 = 9
// c/c++: -1 = 0 + -1, -1 / 10 = 0, -1 % 10 = -1

#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        // int sign = x < 0? -1:1;
        long long ret = 0;
        while (x){
            ret*=10;
            ret += x%10;
            x/=10;
        }
        if (((1<<31))-1 < ret || int((1<<31)) > ret) return 0;
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    // cout<<-1%10<<endl;
    Solution s;
    cout<<s.reverse(-321)<<endl;
    cout<<s.reverse(-120)<<endl;
    cout<<s.reverse(1234567899)<<endl;
    cout<<s.reverse(1463847412)<<endl;
    cout<< ((1<<31) - 1)<<endl;
    return 0;
}
