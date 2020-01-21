#include <iostream>
#include <vector>

using namespace std;

// divide and conquer
// quick select
// https://www.cnblogs.com/LinMiaoJia/p/QuickSelect.html
class Solution {
private:
    // topK
    int _majorityElement(vector<int>& nums, int start, int end, int k) {
        int pivot = nums[end];
        int left = start;
        int cnt = 1;
        for (int i = start; i < end; ++i) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[left]);
                ++left;
            } else if (nums[i] == pivot) cnt++;
        }
        swap(nums[left], nums[end]);
        if (cnt > k || left == k) return pivot;
        if (left < k) return _majorityElement(nums, left + 1, end, k);
        return _majorityElement(nums, start, left - 1, k);
    }
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        return _majorityElement(nums, 0, n-1, (n-1)/2);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {3,2,3};
    cout<<s.majorityElement(nums)<<endl;
    return 0;
}
