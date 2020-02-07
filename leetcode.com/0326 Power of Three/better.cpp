#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(!n)
            return false;
        double val = (log10(n) / log10(3));
        return fmod(val, 1)==0;
    }
};