#include <iostream>
#include <vector>

using namespace std;

// ref: C++, concise solution, O(n) time O(1) space
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108867/C%2B%2B-concise-solution-O(n)-time-O(1)-space

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int s0 = 0, s1 = INT32_MIN;
        for (int p: prices) {
          int t = s0;
          s0 = max(s0, s1+p);
          s1 = max(s1, s0 - p - fee);
        }
        return s0;
    }
};
