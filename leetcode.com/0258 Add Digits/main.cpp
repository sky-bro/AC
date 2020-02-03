#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        while (num > 9) {
            int n = num;
            num = 0;
            while (n) {
                num += n % 10;
                n /= 10;
            }
        }
        return num;
    }
};