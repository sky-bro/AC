#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    inline bool no_zero_int(int val) {
        while (val) {
            if (val % 10 == 0) {
                return false;
            }
            val /= 10;
        }
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> result = {1, n-1};
        for (; result[0] <= n/2; ++result[0], --result[1]) {
            if (no_zero_int(result[0]) && no_zero_int(result[1])) break;
        }
        return result;
    }
};