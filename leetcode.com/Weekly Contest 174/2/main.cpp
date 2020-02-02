#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
}

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size(); if (n == 0) return 0;
        unordered_map<int, int> mp;
        for (int i: arr) {
            mp[i]++;
        }
        vector<pair<int, int>> vp(mp.begin(), mp.end());
        sort(vp.begin(), vp.end(), cmp);
        int cnt = 0;
        int i = 0;
        for (; cnt < n/2; ++i) {
            cnt += vp[i].second;
        }
        return i;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {3,3,3,3,5,5,5,2,2,7};
    Solution s;
    cout<<s.minSetSize(nums)<<endl;
    return 0;
}
