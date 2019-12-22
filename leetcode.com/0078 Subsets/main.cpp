#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void _subsets(int idx, int n, vector<int> &nums, vector<int> &path, vector<vector<int>> &result) {
        if (idx == n) {
            result.push_back(path);
            return;
        }

        path.push_back(nums[idx]);
        _subsets(idx+1, n, nums, path, result);
        path.pop_back();
        _subsets(idx+1, n, nums, path, result);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        _subsets(0, nums.size(), nums, path, result);
        return result;    
    }
};