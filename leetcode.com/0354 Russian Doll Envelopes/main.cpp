#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ref: https://leetcode.com/problems/russian-doll-envelopes/discuss/82763/Java-NLogN-Solution-with-Explanation
// 300. Longest Increasing Subsequence https://leetcode.com/problems/longest-increasing-subsequence/
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        int n = envelopes.size();
        if (n == 0) return 0;
        vector<int> dp;
        for (auto &envelope: envelopes) {
            auto it = lower_bound(dp.begin(), dp.end(), envelope[1]);
            if (it == dp.end()) dp.push_back(envelope[1]);
            else *it = envelope[1];
        }
        return dp.size();
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> envelopes = {{5,4},{6,4},{6,7},{2,3}};
    envelopes = {{46,89},{50,53},{52,68},{72,45},{77,81}};
    cout<<s.maxEnvelopes(envelopes)<<endl;
    return 0;
}
