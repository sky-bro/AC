#include <iostream>
#include <vector>

using namespace std;

// ref: https://leetcode.com/problems/power-of-four/discuss/482197/C%2B%2B-1-line-code-faster-than-100-(0-ms)-with-explanation-no-loopsrecursion
class Solution {
public:
    bool isPowerOfFour(const int& num) {
        return num > 0 && (num & (num - 1)) == 0 && (num & 0xAAAAAAAA) == 0;
    }
};