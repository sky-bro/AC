#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), l = 0, r = n-1;
        if (n == 0) return 0;
        while (l <= r) {
            for (;l<=r && nums[r]==val;--r);
            for (;l<=r && nums[l]!=val;++l);
            if (r<l) break;
            else {
                nums[l] = nums[r--];
            } 
        }
        return r+1;
    }
};