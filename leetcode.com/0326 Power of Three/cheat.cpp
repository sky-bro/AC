#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        // maximum power of 3 within int32: 0x4546B3DB
        return (n>0 && (0x4546B3DB % n)==0);
    }
};