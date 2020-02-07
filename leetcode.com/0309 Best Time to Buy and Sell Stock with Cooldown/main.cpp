#include <iostream>
#include <vector>

using namespace std;

// ref: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/392142/9-line-C%2B%2B-O(n)-time-O(1)-space-(detailed-explanation)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy, sell = 0;
        int buy_pre = INT32_MIN, sell_pre = 0, sell_pre2 = 0;
        for (int price: prices) {
            buy = max(buy_pre, sell_pre2 - price);
            sell = max(sell_pre, buy_pre + price);

            buy_pre = buy;
            sell_pre2 = sell_pre;
            sell_pre = sell;
        }
        return sell;
    }
};