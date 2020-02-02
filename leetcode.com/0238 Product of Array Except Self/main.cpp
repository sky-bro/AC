#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), i = 0;
        vector<int> output(n, 1);
        
        for (i = 1; i < n; ++i) output[i] = output[i-1] * nums[i-1];

        int k = nums[n-1];
        for (i = n - 2; i >=0; --i) {
            output[i] *= k;
            k *= nums[i];
        }
        
        return output;
    }
};