// O(N*N)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) 
    {
        int sLen = s.length(), maxLen = 0, maxStart = 0;
        int i = 0, l = 0, r = 0, len = 0;
        while(i<sLen-maxLen/2)
        {
            l = r = i;
            while(r<sLen-1 && s[r+1]==s[r]) r++;
            i = r+1; // 牛逼
            while(l>0 && r<sLen-1 && s[r+1]==s[l-1]) l--, r++;
            len = r-l+1;
            if(maxLen < len) maxLen = len, maxStart = l;
        }
        return s.substr(maxStart, maxLen);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str("abca");
    // cout<<string(str.begin()+1, str.begin()+ 1 + 3)<<endl;
    cout<<s.longestPalindrome("abbd")<<endl;
    return 0;
}
