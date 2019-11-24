#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;
        int n = s.length();
        int max_len = 1, start = 0;
        vector<vector<int>> vv(n);

        vv[0].resize(n, 1);
        for (int i = 0; i <= n-2; ++i) {
            if (s[i] == s[i+1]) {
                vv[1].push_back(1);
                if (max_len == 1) {
                    max_len = 2;
                    start = i;
                }
            } else {
                vv[1].push_back(0);
            }
        }
            
        for (int i = 2; i <= n-1; ++i) { // 长度为i+1的串
            for (int j = 0; j <= n-i-1; ++j) { // 起点为j
                if (vv[i-2][j+1] && s[j] == s[j+i]) {
                    vv[i].push_back(1);
                    if (max_len <= i) {
                        max_len = i+1;
                        start = j;
                    }
                } else {
                    vv[i].push_back(0);
                }

            }
            if (max_len <= i-1)
                break;
        }
        return s.substr(start, max_len);
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
