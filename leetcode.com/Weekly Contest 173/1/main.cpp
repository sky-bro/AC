#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        int l = 0, r = s.length() - 1;
        if (r == -1) return 0;
        while (l < r) {
            if (s[l] == s[r]) {
                ++l;
                --r;
            } else break;
        }
        if (l >= r) return 1;
        return 2;
    }
};