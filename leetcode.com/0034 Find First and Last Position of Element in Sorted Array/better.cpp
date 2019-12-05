#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if (nums.empty()) return res;
        
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] >= target) right = mid;
            else left = mid + 1;
        }
        if (nums[left] == target) res[0] = left;
        
        left = 0;
        right = nums.size() - 1;
        while (left < right) {
            mid = left + (right - left) / 2 + 1;
            if (nums[mid] <= target) left = mid;
            else right = mid - 1;
        }
        if (nums[right] == target) res[1] = right;
        return res;
    }
};

