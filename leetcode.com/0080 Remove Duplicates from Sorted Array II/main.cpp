#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int left = 2, right = 2;
        for (; right < n; ++right) {
            if (nums[right] != nums[left-1] || nums[right] != nums[left-2]) {
                nums[left++] = nums[right];
            }
        }
        return left;
    }
};