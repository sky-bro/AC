#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        int result = 0;
        int div = 1000, tmp;
        while (num) {
            tmp = num / div;
            if (tmp == 6) {
                result += 3 * div + num;
                break;
            } else {
                result += tmp * div;
            }
            num %= div;
            div /= 10;
        }
        return result;
    }
};