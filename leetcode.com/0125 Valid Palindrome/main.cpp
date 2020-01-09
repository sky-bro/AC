#include <iostream>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        for (int i = 0, j = n-1; i < j; ++i, --j) {
            for (; !isalnum(s[i]) && i < j; ++i);
            for (; !isalnum(s[j]) && i < j; --j);
            if (i == j) return true;
            if (tolower(s[i]) != tolower(s[j])) return false;
        }
        return true;
    }
};