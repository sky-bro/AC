#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    size_t n;
    void _subsetsWithDup(vector<int> &nums, int idx, vector<int> &path) {
        if (idx == n) {
            result.push_back(path);
            return;
        }
        int m = 1;
        for (;idx + m != n && nums[idx+m] == nums[idx]; ++m);
        _subsetsWithDup(nums, idx+m, path);
        for (int i = 1; i <= m; ++i) {
            path.push_back(nums[idx]);
            _subsetsWithDup(nums, idx+m, path);
        }
        for (int i = 1; i <= m; ++i) {
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        result.clear();
        n = nums.size();
        vector<int> path;
        _subsetsWithDup(nums, 0, path);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 2};
    Solution s;
    s.subsetsWithDup(nums);
    return 0;
}
