#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/number-of-digit-one/discuss/64411/Simple-math-solution-0ms-in-C%2B%2B
class Solution 
{
public:
    int countDigitOne(int num) 
    {
        int sum = 0;
        // check each digit, either from right to left, or from left to right
        // easier from right to left
        for(long i = 1; i <= num; i *= 10)
        {
            int a = num/i;
            int b = num%i;
            // three cases:
            // case 1: cur digit == 0, continue
            // case 2: cur digit == 1, sum += (b+1)
            // case 3: cur digit >= 2, sum += (a+8)/10*i or sum += a/10*i + a>1?1:0;
                // like num = 12, i = 1, 1-th digit could be 1 in two cases: 11, 01
            sum += (a+8)/10*i+(a%10==1)*(b+1);
        }
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    int num;
    Solution s;
    while (cin>>num) {
        cout<<s.countDigitOne(num)<<endl;
    }
    return 0;
}
