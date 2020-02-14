#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> mp;
        for (int num: nums) mp[num]++;
        vector<pair<int, int>> arr(mp.begin(), mp.end());
        nth_element(arr.begin(), arr.begin()+k, arr.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.second > b.second;
        });
        for (int i = 0; i < k; ++i) {
            res.push_back(arr[i].first);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {1};
    int k = 1;

    nums = {1,1,1,2,2,3};
    k = 0;
    s.topKFrequent(nums, k);
    return 0;
}
