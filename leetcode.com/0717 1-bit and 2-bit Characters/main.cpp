#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int  n = bits.size() - 1;
        // 0: 1bit / 1: 2bits
        int i = 0;
        while (i < n) {
          i += bits[i] ? 2 : 1;
        }
        return i == n;
    }
};
