#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int n;
    int _numDecodings(string s, vector<int> &dp, int idx) {
        if (idx == n) {
            return 1;
        }
        if (idx > n) return 0;

        if (dp[idx] != -1) return dp[idx];
        switch (s[idx])
        {
        case '0':
            return dp[idx] = 0;
            break;
        case '1':
            return dp[idx] = (_numDecodings(s, dp, idx+1) + _numDecodings(s, dp, idx+2));
            break;
        case '2':
            if (idx + 1 < n && s[idx+1] <= '6') {
                return dp[idx] = (_numDecodings(s, dp, idx+1) + _numDecodings(s, dp, idx+2));
            } else {
                return dp[idx] = _numDecodings(s, dp, idx+1);
            }
            break;
        default:
            return dp[idx] = _numDecodings(s, dp, idx+1);
            break;
        }
    }
public:
    int numDecodings(string s) {
        vector<int> dp(s.length(), -1);
        n = s.length();
        return _numDecodings(s, dp, 0);
    }
};

int main(int argc, char const *argv[])
{
    string str;
    Solution s;
    while (cin>>str)
        cout<<s.numDecodings(str)<<endl;
    return 0;
}
