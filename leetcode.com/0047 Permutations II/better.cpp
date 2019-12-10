#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        do{
            result.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        return result;
    }
};

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
