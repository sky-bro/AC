#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small = INT32_MAX, big = INT32_MAX;
        for (int num: nums) {
            if (num <= small) small = num;
            else if (num <= big) big = num;
            else return true;
        }
        return false;
    }
};