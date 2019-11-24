// O(N) manacher's Algorithm
// 但提交结果不如better.cpp，better.cpp也更易理解

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;
        string prep = "#";
        for (auto ch : s) { prep += ch; prep += "#";}
        const int size_p = prep.size();
        vector<int> dp(size_p, 0);
        int center = 0, bCur = 0;
        for (int i = 0; i < size_p; i++) {
            int mirror = center - (i - center);
            dp[i] = bCur <= i ? 0 : min(bCur - i, dp[mirror]);
            int start = i - dp[i], end = i + dp[i];
            while (start - 1 >= 0 && end + 1 < size_p && prep[start - 1] == prep[end + 1]) {
                --start;
                ++end; 
                ++dp[i];
            }
            if (i + dp[i] > bCur) {
                bCur = i + dp[i];
                center = i;
            }
        }
        center = max_element(dp.begin(), dp.end()) - dp.begin();
        return s.substr((center - dp[center])/2, dp[center]);
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
