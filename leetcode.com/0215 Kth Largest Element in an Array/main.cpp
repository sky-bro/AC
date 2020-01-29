#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int findKthLargest(vector<int>& nums, int left, int right, int k) {
        int l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < nums[left]) {
                swap(nums[l], nums[r--]);
            } else ++l;
        }
        swap(nums[left], nums[r]);
        if (r == k) return nums[k];
        else if (k < r) return findKthLargest(nums, left, r-1, k);
        else return findKthLargest(nums, r+1, right, k);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, 0, nums.size()-1, k-1);
    }
};