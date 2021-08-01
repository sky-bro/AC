#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

const int MOD = 1e9 + 7;
typedef long long ll;

class Solution {
private:
    int n;
    // dp[i][j]
    // i开始的子序列个数
    ll dfs(vector<vector<ll>> &dp, vector<int>& A, int i, int j) {
        if (j == n) {
            return 0;
        }
        if (~dp[i][j]) return dp[i][j];
        ll nres = dfs(dp, A, i, j+1);
        ll res = 0;
        if (A[j] == i) {
            res += (nres ? (2 * nres) + (i == 2) : (i == 2));
            if (i != 2) res += dfs(dp, A, i + 1, j + 1);
        } else res = nres;
        return dp[i][j] = res % MOD;
    }
public:
    int countSpecialSubsequences(vector<int>& A) {
        n = A.size();
        vector<vector<ll>> dp(3, vector<ll>(n, -1));
        ll res = dfs(dp, A, 0, 0);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> A = {0, 1, 2, 2};
    A = {0, 1, 2, 0, 1, 2};
    cout << s.countSpecialSubsequences(A) << endl;
    return 0;
}

