#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() > b.length()) return addBinary(b, a);
        int m = a.length(), n = b.length(), carry = 0;
        // 和最多n+1位，字符串结尾再+1
        char *sum = new char[n + 2]{0};
        int i = 1;
        for (; i <= m; ++i) {
            sum[n+1-i] = a[m-i] - '0' + b[n-i] - '0' + carry;
            carry = sum[n+1-i] / 2;
            sum[n+1-i] %= 2;
            sum[n+1-i] += '0';
        }
        for (; i <= n; ++i) {
            sum[n+1-i] = b[n-i] - '0' + carry;
            carry = sum[n+1-i] / 2;
            sum[n+1-i] %= 2;
            sum[n+1-i] += '0';
        }

        if (carry) {
            sum[0] = '1';
            string result = sum;
            delete [] sum;
            return result;
        } else {
            string result = sum+1;
            delete [] sum;
            return result;
        }
    }
};