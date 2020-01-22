#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    int m, n, result;
    // is valid?
    bool dfs(vector<vector<int>>& dungeon, int i, int j, int cur_health, vector<vector<int>>& dp) {
        if (cur_health <= 0) return false;
        cur_health += dungeon[i][j];
        if (cur_health <= dp[i][j]) return false;
        dp[i][j] = cur_health;
        if (i == m - 1 && j == n - 1) {
            if (cur_health <= 0) return false;
            return true;
        }
        if (i + 1 < m && dfs(dungeon, i+1, j, cur_health, dp) ) return true;
        if (j + 1 < n && dfs(dungeon, i, j+1, cur_health, dp) ) return true;
        return false;
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();
        int l = 0, r = INT32_MAX;
        while (l < r) {
            int mid = l + (r - l) / 2;
            vector<vector<int>> dp(m, vector<int>(n, INT32_MIN));
            if (dfs(dungeon, 0, 0, mid, dp)) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> dungeon = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
    Solution s;
    cout<<s.calculateMinimumHP(dungeon)<<endl;
    return 0;
}
