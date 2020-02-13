#include <iostream>
#include <vector>

using namespace std;

// math behind: https://leetcode.com/problems/integer-break/discuss/80721/Why-factor-2-or-3-The-math-behind-this-problem.
class Solution {
public:
    int integerBreak(int n) {
        switch (n)
        {
        case 2:
        case 3:
            return n-1;
        default:
            int res = 1;
            while (n != 2 && n != 4 && n != 3) {
                res *= 3;
                n -= 3;
            }
            res *= n;
            return res;
        }
    }
};