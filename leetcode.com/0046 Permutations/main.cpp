#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int begin;
    int end;
    vector<vector<int>> result;
    void _permute(vector<int>& nums) {
        if (begin >= end) {
            result.push_back(nums);
            return;
        }
        for (int i = begin; i < end; ++i) {
            swap(nums[i], nums[begin]);
            ++begin;
            _permute(nums);
            --begin;
            swap(nums[i], nums[begin]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        begin = 0;
        end = nums.size();
        _permute(nums);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {1,2,3};
    auto result = s.permute(nums);
    for (auto &vi: result){
        for (auto &i: vi) {
            cout<< i << " ";
        }
        cout<<endl;
    }
    return 0;
}
