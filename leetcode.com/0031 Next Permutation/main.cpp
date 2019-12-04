#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), min_tmp, min_j;
        if (n <= 1) return;
        for (int i  = n-2; i >= 0; --i) {
            int j = i + 1;
            min_tmp = INT32_MAX;
            
            for (; j < n; ++j) {
                // 这里判断要加上等于才能从大到小
                if (nums[j] > nums[i] && nums[j] <= min_tmp) {
                    min_j = j;
                    min_tmp = nums[j];
                }
            }
            if (min_tmp != INT32_MAX) {
                swap(nums[i], nums[min_j]);
                // 我没有理解到这里实际上就是从大到小的顺序
                // sort(nums.begin()+i+1, nums.end());
                reverse(nums.begin()+i+1, nums.end());
                return;
            }
        }

        // reverse
        reverse(nums.begin(), nums.end());
        return;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums({2,3,1});
    for (auto x: nums) {
        cout<<x<<" ";
    }
    cout<<endl;
    Solution s;
    s.nextPermutation(nums);
    for (auto x: nums) {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}