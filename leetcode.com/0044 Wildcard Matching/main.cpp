#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = p.length(), n = s.length();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = 1;
        for (int i = 1; i <= m && p[i-1] == '*'; ++i) dp[i][0] = true;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (p[i] == '*' && (dp[i+1][j] || dp[i][j] || dp[i][j+1])) {
                    dp[i+1][j+1] = true;
                } else if ((p[i] == '?' || p[i] == s[j]) && dp[i][j]) {
                    dp[i+1][j+1] = true;
                }
            }
        }
        return dp[m][n];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string a, b;
    while (cin>>a>>b)
        cout<<s.isMatch(a, b)<<endl;
    return 0;
}
