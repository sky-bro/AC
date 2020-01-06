#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly_nums(n+1);
        ugly_nums[1] = 1;

        int ia = 1, ib = 1, ic = 1, a = ugly_nums[ia] * 2, b = ugly_nums[ib] * 3, c = ugly_nums[ic] * 5;
        for (int i = 2; i <= n; ++i) {
            if (a <= b) {
                if (a <= c) {
                    // min(a, b, c) == a
                    ugly_nums[i] = a;
                    a = ugly_nums[++ia] * 2;
                } else {
                    // min(a, b, c) == c
                    ugly_nums[i] = c;
                    c = ugly_nums[++ic] * 5;
                }
            } else if (c <= b) {
                // min(a, b, c) == c
                ugly_nums[i] = c;
                c = ugly_nums[++ic] * 5;

            } else {
                // min(a, b, c) == b
                ugly_nums[i] = b;
                b = ugly_nums[++ib] * 3;
            }
            if (ugly_nums[i-1] == ugly_nums[i]) --i;
        }
        return ugly_nums[n];
    }
};