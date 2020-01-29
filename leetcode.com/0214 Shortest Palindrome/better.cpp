#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.empty())   return s;
        int n = s.length();
        int i = 0, last = 1;
        
        while(i < n){
            int left = i, right = i;
            while (right < n - 1 && s[right + 1] == s[right]) ++right;  //skip duplicate
            i = right + 1;  //next, jump to i
            while (right < n && left >= 0 && s[right] == s[left]) {
                ++right; --left;
            }
            if(left<0)  last = right;           
        }
        string str(s.rbegin(), s.rbegin()+n-last);
        return str + s;
    }
};