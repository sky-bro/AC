#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ref: https://leetcode.com/problems/wiggle-sort-ii/discuss/77677/O(n)%2BO(1)-after-median-Virtual-Indexing
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        
        // Find a median.
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        
        // Index-rewiring.
        #define A(i) nums[(1+2*(i)) % (n|1)]

        // 3-way-partition-to-wiggly in O(n) time with O(1) space.
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (A(j) > mid)
                swap(A(i++), A(j++)); // put bigger ones on the "left"
            else if (A(j) < mid)
                swap(A(j), A(k--)); // put smaller ones on the "right"
            else
                j++;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {1,5,1,1,6,4};
    s.wiggleSort(nums);

    nums = {4,5,5,6};
    s.wiggleSort(nums);
    // vector<int> arr = {8,7,6,5,4,3,2,1};
    // nth_element(arr.begin(), arr.begin()+3, arr.end());
    // for (int i: arr) {
    //     cout<<i<<" ";
    // }
    return 0;
}
