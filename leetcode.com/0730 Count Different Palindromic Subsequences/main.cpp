// ref: Java 96ms DP Solution with Detailed Explanation
// https://leetcode.com/problems/count-different-palindromic-subsequences/discuss/109507/Java-96ms-DP-Solution-with-Detailed-Explanation
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9+7;

class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int n = S.length();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; ++i) dp[0][i] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; i + j < n; ++j) {
                long long cur = 0;
                if (S[j] == S[i+j]) {
                    cur = (i-2 < 0 ? 0 : dp[i-2][j+1]) * 2LL;
                    int lo = j + 1, hi = i+j-1;
                    while (lo <= hi && S[lo] != S[j]) ++lo;
                    while (lo <= hi && S[hi] != S[j]) --hi;
                    if (lo == hi) ++cur;
                    else if (lo > hi) cur += 2;
                    else if (lo < hi-1) cur -= dp[hi-lo-2][lo+1];
                } else  cur = dp[i-1][j] - (i-2 < 0 ? 0 : dp[i-2][j+1]) + dp[i-1][j+1];
                dp[i][j] = (cur%MOD + MOD) % MOD;
            }
        }
        return dp[n-1][0];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str;
    while (cin>>str) {
        cout<<s.countPalindromicSubsequences(str)<<endl;
    }
    return 0;
}
