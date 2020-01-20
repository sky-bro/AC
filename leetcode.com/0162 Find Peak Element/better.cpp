#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n - 1;
        
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (mid == l) { // two elements left
                if (nums[l] < nums[r]) return r;
                else return l;
            }
            if (nums[mid] < nums[mid+1]) l = mid + 1; // peak_idx > mid
            else r = mid; // peak_idx <= mid
        }

        return l;
    }
};