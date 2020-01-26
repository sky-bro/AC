#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int n;
    int _minDifficulty(vector<int>& jobDifficulty, int d, int idx, vector<vector<int>>& dp) {
        int today_difficulty = jobDifficulty[idx];
        if (dp[d-1][idx] != -1) return dp[d-1][idx];
        if (d == 1) {
            for (int i = idx + 1; i < n; ++i) {
                if (today_difficulty < jobDifficulty[i]) today_difficulty = jobDifficulty[i];
            }
            return dp[d-1][idx] = today_difficulty;
        }
        
        int result = INT32_MAX;
        // 从idx-th job一直做到i-th job
        for (int i = idx; i <= n - d; ++i) {
            if (today_difficulty < jobDifficulty[i]) today_difficulty = jobDifficulty[i];
            int tmp = today_difficulty + _minDifficulty(jobDifficulty, d-1, i+1, dp);
            if (tmp < result) result = tmp;
        }
        return dp[d-1][idx] = result;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n = jobDifficulty.size();
        if (d > n) return -1;
        vector<vector<int>> dp(d, vector<int>(n, -1));
        return _minDifficulty(jobDifficulty, d, 0, dp);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> jobDifficulty = {9,9,9};
    int d = 4;
    Solution s;
    cout<<s.minDifficulty(jobDifficulty, d)<<endl;
    return 0;
}
