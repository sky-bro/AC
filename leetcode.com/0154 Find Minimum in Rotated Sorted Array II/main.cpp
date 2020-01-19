#include <iostream>
#include <vector>

using namespace std;

// may contain duplicate numbers, harder
class Solution {
private:
    void _findMin(vector<int>& nums, int l, int r, int &result) {
        if (l > r) return;
        if (l == r) {
            if (result > nums[l]) result = nums[l];
            return;
        }
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < result) result = nums[mid];
            if (nums[mid] < nums[r]) r = mid - 1;
            else if (nums[mid] > nums[r]) l = mid + 1;
            else if (nums[mid] > nums[l]) {
                if (nums[l] < result) result = nums[l];
                return;
            }
            else if (nums[mid] < nums[l]) r = mid - 1;
            else {
                _findMin(nums, mid + 1, r-1, result);
                _findMin(nums, l + 1, mid - 1, result);
                return;
            }
        }
    }
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int result = nums[0];
        _findMin(nums, l, r, result);
        return result;
    }
};