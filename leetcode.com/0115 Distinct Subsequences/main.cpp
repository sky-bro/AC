#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<unsigned>> dp(m+1, vector<unsigned>(n+1));
        for (int i = 0; i <= n; ++i) dp[0][i] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = i; j <= n-(m-i); ++j) {
                if (t[i-1] == s[j-1]) {
                    if (dp[i][j-1]) dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                    else dp[i][j] = dp[i-1][j-1];
                } else dp[i][j] = dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};