#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSteps (int num) {
        int steps = 0;
        while (num) {
            if (num&1) {
                num >>= 1;
                steps += num ? 2 : 1;
            } else {
                num >>= 1;
                steps += 1;
            }
        }
        return steps;
    }
};