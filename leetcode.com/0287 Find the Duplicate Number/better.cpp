#include <iostream>
#include <vector>

using namespace std;

// similar to find the start of the loop in a linked list
// ref: https://leetcode.com/problems/find-the-duplicate-number/discuss/72975/O(nlogn)-and-O(n)-solutions-in-C%2B%2B-well-explained
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        fast = 0;
        while(fast != slow)//find the start of the loop which means at least two integer are the same value;
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
