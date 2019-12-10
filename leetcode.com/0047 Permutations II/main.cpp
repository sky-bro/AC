#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    void _permuteUnique(vector<vector<int>> &result, vector<int> &nums, vector<bool> &visited, vector<int> &path) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i]) continue;
            path.push_back(nums[i]);
            visited[i] = true;
            _permuteUnique(result, nums, visited, path);
            path.pop_back();
            visited[i] = false;
            for (; i+1 < nums.size() && nums[i+1] == nums[i]; ++i);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        _permuteUnique(result, nums, visited, path);
        return result;
    }
};

/*
// use swap, no alias, slow
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        helper(res, nums, 0);
        return res;
    }
    
    void helper(vector<vector<int>> &res, vector<int> nums, int index) {
        if (index == nums.size()) {
            res.push_back(nums);
            return;
        }
        
        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[index]) continue;
            swap(nums[index], nums[i]);
            helper(res, nums, index+1);
            //swap(nums[index], nums[i]);
        }
    }
};
*/

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,1,2};
    Solution s;
    auto result = s.permuteUnique(nums);
    for (auto &vi: result) {
        for (auto &i: vi) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
