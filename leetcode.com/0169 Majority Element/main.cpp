#include <iostream>
#include <vector>

using namespace std;

// bit manipulation
// https://leetcode.com/problems/majority-element/discuss/51838/Simple-bit-manipulation-solution
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = INT32_MAX;
        for(int n=0; n <= 31; n++) {
            int numOf0Bits=0;
            int numOf1Bits=1;
            for(auto num : nums) {
                int bit=( num & (1 << n) ) >> n;
                if(bit)
                    numOf1Bits++;
                else
                    numOf0Bits++;
            }
            if(numOf1Bits > numOf0Bits) {
                res = res | (1 << n);
            } else {
                res = res & ( ~ ( 1 << n) );
            }
        }
        return res;
    }
};