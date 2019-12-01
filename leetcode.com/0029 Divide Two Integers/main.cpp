// https://leetcode.com/problems/divide-two-integers/discuss/349025/C%2B%2B-0-ms-(100)-followed-all-rules

#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
    public:
    int divide(int dividend, int divisor) {
        
        if(dividend == INT32_MIN && divisor == -1)
            return INT32_MAX;
        if(divisor == 1)
            return dividend;
        
        if(divisor == -1 )
            return -1*dividend;
        
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1; 

        // remove sign of operands 
        long div = dividend; 
        long dsr = divisor; 
        div = abs(div);
        dsr = abs(dsr);
        long long  tmp = 0;
        long long quotient = 0;
        // 这里模拟除法运算，二进制的，从第31位一直到第0位
        for(int i = 31; i>= 0; --i) {
            if(tmp + (dsr<<i) <= div) {
                tmp += dsr << i; 
                quotient |= 1LL << i; 
            }
        }
        return sign * quotient;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout<<s.divide(1<<31, -1)<<endl;
    return 0;
}
