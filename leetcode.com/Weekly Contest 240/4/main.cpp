#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

class Solution {
private:
    int n;
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        n = colors.size();
        vector<vector<int>> G(n);
        vector<int> in(n);
        for (auto &v: edges) {
            G[v[0]].push_back(v[1]);
            ++in[v[1]];
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) if (!in[i]) q.push(i);
        int res = 0;
        vector<vector<int>> dp(n, vector<int>(26));
        while (!q.empty()) {
            int x = q.front(); q.pop();
            int c = colors[x] - 'a';
            res = max(res, ++dp[x][c]);
            for (int y: G[x]) {
                for (int i = 0; i < 26; ++i) dp[y][i] = max(dp[y][i], dp[x][i]);
                if (--in[y] == 0) q.push(y);
            }
        }
        for (int i = 0; i < n; ++i) if (in[i]) return -1;
        return res;        
    }
};

int main(int argc, char const *argv[])
{
    string c = "abaca";
    vector<vector<int>> A = {{0,1},{0,2},{2,3},{3,4}};
    Solution s;
    cout << s.largestPathValue(c, A) << endl;
    return 0;
}

