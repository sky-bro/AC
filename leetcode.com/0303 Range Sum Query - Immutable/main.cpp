#include <iostream>
#include <vector>

using namespace std;

// ref: https://leetcode.com/problems/range-sum-query-immutable/discuss/500329/C%2B%2B-Logical-DP-Solution
class NumArray {
private:
    vector<int> accumulate{0};
public:
    NumArray(vector<int>& nums) {
        for (int num: nums) {
            accumulate.push_back(num+accumulate.back());
        }
    }
    
    int sumRange(int i, int j) {
        return accumulate[j+1] - accumulate[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */