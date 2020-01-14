#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        auto xor_op = [](int x, int y) { return x^y; };
        return accumulate(nums.begin(), nums.end(), 0, xor_op);
    }
};