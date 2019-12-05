#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // int search(vector<int>& nums, int target) {
    //     int s = 0, e = nums.size()-1;
    //     while (s <= e) {
    //         int m = (e + s) / 2;
            
    //         if (nums[m] == target) return m;
            
    //         if (nums[m] > target) {
    //             if (nums[s] <= target || nums[s] > nums[m])
    //                 e = m-1;
    //             else
    //                 s = m+1;
    //         } else {
    //             if (nums[s] > target || nums[s] <= nums[m]) 
    //                 s = m+1;
    //             else 
    //                 e = m-1;
    //         }
    //     }
        
    //     return -1;
    // }
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1, m;
        while (l <= r) {
            m = l + (r-l)/2;
            if (nums[m] == target) {
                return m;
            } else if (nums[m] < target) { // need bigger nums[m]
                // three cases:
                if (nums[m] < nums[l]) { // 1. pivot point on the left
                    if (target <= nums[r]) { // target in right half
                        l = m + 1;
                    } else { // target in left half
                        r = m - 1;
                    }
                } else if (nums[m] > nums[r]) { // 2. pivot point on the right
                    l = m + 1;
                    r = r - 1;
                } else { // 3. normal
                    l = m + 1;
                }
            } else {  // need smaller nums[m]
                 // three cases:
                if (nums[m] < nums[l]) { // 1. pivot point on the left
                    l = l + 1;
                    r = m - 1;
                } else if (nums[m] > nums[r]) { // 2. pivot point on the right
                    if (target <= nums[r]) {
                        l = m + 1;
                    } else {
                        r = m - 1;
                    }
                } else { // 3. normal
                    r = m - 1;
                }
            }
        }
        return -1;
    }
};