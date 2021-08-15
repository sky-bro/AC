#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

// 两个思路，一个是正向遍历点，UF找到一条占据所有列的组合
// 另外一个是反向遍历，UF找到通路 -- 更简单

int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};
class Solution {
private:
    vector<int> ids;
    int F(int x) {
        return x == ids[x] ? x : ids[x] = F(ids[x]);
    }
    void U(int p, int q) {
        ids[F(p)] = F(q);
    }
public:
    int latestDayToCross(int m, int n, vector<vector<int>>& A) {
        #define idx(x, y) (x*n + y + 1)
        int sz = m * n;
        ids.resize(sz + 2);
        iota(ids.begin(), ids.end(), 0);
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = m * n - 1; i >= 0; --i) {
            int x = A[i][0] - 1, y = A[i][1] - 1;
            int ind = idx(x, y);
            vis[x][y] = 1;
            for (int j = 0; j < 4; ++j) {
                int nx = x + di[j], ny = y + dj[j];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && vis[nx][ny]) {
                    U(idx(nx, ny), ind);
                }
            }
            if (x == 0) {
                U(0, ind);
            }
            if (x == m - 1) {
                U(sz + 1, ind);
            }
            if (F(0) == F(sz + 1)) return i;
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> A = {{1,1}, {2, 1}, {1, 2}, {2,2}};
    cout << s.latestDayToCross(2,2, A) << endl;
    return 0;
}

