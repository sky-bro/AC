#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {

        while (n) {
            if (n&1) {
                n ^= 1;
                if (n == 0) return true;
                else return false;
            }
            n = n >> 1;
        }
        return false;
    }
};