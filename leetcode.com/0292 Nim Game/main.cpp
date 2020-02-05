#include <iostream>
#include <vector>

using namespace std;

// like dp
// 1 1 1 0 1 1 1 0 1
class Solution {
public:
    bool canWinNim(int n) {
        // return n % 4;
        return n & 4;
    }
};