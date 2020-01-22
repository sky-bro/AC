#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0, mask = 1;
        for (int i = 0; i < 32; ++i) {
            result ^= (n & mask) >> i << (31 - i);
            mask = mask << 1;
        }
        return result;
    }
};