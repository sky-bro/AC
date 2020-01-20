#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string result = "";
        string fraction = "";
        unordered_map<long long, long long> m;
        if (numerator < 0 && denominator > 0 || denominator < 0 && numerator > 0) result.push_back('-');
        long long n = (long long)numerator;
        long long d = (long long)denominator;
        n = abs(n);
        d = abs(d);
        result += to_string(n / d);
        n %= d;
        n *= 10;
        int idx = -1;
        for (int i = 0; n; ++i, n *= 10) {
            if (m.count(n)) {
                idx = m[n];
                break;
            }
            m[n] = i;
            fraction.push_back(n / d + '0');
            n %= d;

        }
        if (fraction.empty()) return result;
        if (idx == -1) return result + "." + fraction;
        return result + "." + fraction.substr(0, idx) + "(" + fraction.substr(idx) + ")";
    }
};