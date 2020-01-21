#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for (char c: s) {
            result *= 26;
            result += c - 'A' + 1;
        }
        return result;
    }
};