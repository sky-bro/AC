#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long double result = 1.0, base = x;
        long _n = n;
        bool is_negative = n < 0;
        if (is_negative) _n = -_n;
        while (_n) {
            if (_n & 1) {
                result *= base;
            }
            base *= base;
            _n = _n >> 1;
        }
        if (is_negative) result = 1/result;
        return result;
    }
};