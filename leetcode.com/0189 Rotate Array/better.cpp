#include <iostream>
#include <vector>

using namespace std;

// O(1) extra space, O(n) time, no math, better
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if (k == 0) return;
        int count = 0;
        for(int i=0;count<n;i++)
        {
            int j = i;
            int value = nums[j];
            do{
                j = (j+k)%n;
                swap(nums[j], value);
                count++;
            }while (j!=i);
        }
    }
};