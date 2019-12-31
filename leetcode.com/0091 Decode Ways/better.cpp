#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+2, 0);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') dp[i] = 0;
            else if (s[i] == '1' || s[i] == '2' && i+1 < n && s[i+1] <= '6') dp[i] = dp[i+1] + dp[i+2];
            else dp[i] = dp[i+1];
        }
        return dp[0];
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
