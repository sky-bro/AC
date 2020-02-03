#include <iostream>
#include <vector>

using namespace std;

// ref: https://leetcode.com/problems/single-number-iii/discuss/342714/Best-Explanation-C%2B%2B
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int XOR = 0, mask = 1;
        for (int num: nums) {
            XOR ^= num;
        }
        while ((mask & XOR) == 0) {
            mask = mask<<1;
        }

        int a = 0, b = 0;
        for (int num: nums) {
            if (num & mask) a ^= num;
            else b ^= num;
        }
        return {a, b};
    }
};