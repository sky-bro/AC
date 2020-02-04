#include <iostream>
#include <vector>

using namespace std;

// binary search
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1, h = nums.size() - 1;
        while (l < h) {
            int m = l + (h - l) / 2;
            int count_lower = 0, count_m = 0;
            for (int i: nums) {
                if (i < m) count_lower++;
                else if (i == m) count_m++;
            }

            if (count_lower > m - 1) h = m - 1;
            else if (count_m > 1) return m;
            else l = m + 1;
        }
        return l;
    }
};
