#include <iostream>
#include <vector>

using namespace std;

// TLE
class Solution {
private:
    bool check(const string& s, int n, int new_n) {
        int l = 0, r = n - 1- (new_n-n);
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        int new_n = n;
        while (new_n < 2*n) {
            if (check(s, n, new_n)) break;
            ++new_n;
        }

        string front_part(s.rbegin(), s.rbegin()+new_n-n);
        return front_part + s;
    }
};