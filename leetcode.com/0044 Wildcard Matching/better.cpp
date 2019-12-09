#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        // aaa
        //  i
        //  m
        // *a
        //  j
        // s
        
        int i = 0, j = 0;
        int match_idx = -1;
        int star_p = -1;
        
        while(i < s.size()) {
            if(p[j] == s[i] || p[j] == '?') {
                i++; 
                j++;
            } else if (p[j] == '*') {
                star_p = j;
                match_idx = i;
                j++;
            } else if(match_idx >= 0) {
                i = ++match_idx;
                j = star_p + 1;
            } else {
                return false;
            }                        
        }

        while(j < p.size() && p[j] == '*')
            j++;
        
        return j == p.size();
        
    }
};

/*
class Solution {
public:
    bool isMatch(string s, string p) {
        
        int m = s.size(), n = p.size();
        int i = 0, j = 0, asterisk = -1, match;
        while(i < m) {
            if(j < n && p[j] == '*') {
                asterisk = j++;
                match = i;
            }
            
            else if(j < n && (p[j] == s[i] || p[j] == '?')) {
                i++;
                j++;
            }
            
            else if(asterisk >= 0) {
                i = ++match;
                j = asterisk+1;
            }
            else
                return false;
        }
        
        while(j < n && p[j] == '*') j++;
        
        return j == n;
    }
};
*/

int main(int argc, char const *argv[])
{
    Solution s;
    string a, b;
    while (cin>>a>>b)
        cout<<s.isMatch(a, b)<<endl;
    return 0;
}
