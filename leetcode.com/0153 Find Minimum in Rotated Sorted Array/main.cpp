#include <iostream>
#include <vector>

using namespace std;

// no duplicate numbers, simpler
class Solution {
public:
    int findMin(vector<int>& nums) {

        int l = 0, r = nums.size() - 1;
        // if (r < 0) return 0; // 不考虑
        int result = nums[0];
        while (l <= r) {
            int mid = l + (r - l)/2;
            if (nums[mid] < result) result = nums[mid];
            if (nums[mid] < nums[r]) r = mid - 1;
            else l = mid + 1;
        }
        return result;
    }
};