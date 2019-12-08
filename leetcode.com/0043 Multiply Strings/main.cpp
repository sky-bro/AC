#include <iostream>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.length(), len2 = num2.length();
        char *result = new char[len1+len2+1]();
        char *right = result + len1 + len2;
        char *left;
        int tmp;
        for (int i = len1-1; i >= 0; --i ) {
            --right;
            left = right;
            for (int j = len2-1; j >= 0; --j) {
                tmp = (num1[i] - '0') * (num2[j] - '0') + *left;
                *left = tmp % 10;
                *(--left) += tmp / 10;
            }
        }
        for (;*left==0 && left < result + len1 + len2 - 1;++left);
        for (char *_left = left; _left < result + len1 + len2; (*_left++) += '0');
        return string(left);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout<<s.multiply("123", "456")<<endl;
    cout<<s.multiply("9133", "0")<<endl;
    return 0;
}
