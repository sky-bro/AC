#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        vector<int> result;
        int a = tomatoSlices/2 - cheeseSlices, b = cheeseSlices + (cheeseSlices - tomatoSlices/2);
        if (a >= 0 && b >= 0 && a + b == cheeseSlices && 4*a + 2*b == tomatoSlices) {
            result.push_back(a);
            result.push_back(b);
        }
        return result;
    }
};