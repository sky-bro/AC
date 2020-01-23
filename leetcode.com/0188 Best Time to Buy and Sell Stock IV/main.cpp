#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //dp + greedy
    //time: o(n * k)
    //space: o(k)
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() < 2 || k < 1)
            return 0;
        
        if(k >= prices.size() / 2)
            return quick_solve(prices);
        
        vector<int> buy_profit(k+1, INT32_MIN);//buy_profit[i] means i-th buy profit
        vector<int> sell_profit(k+1, 0);//sell_profit[i] means i-th sell profit.
        for(auto& p : prices) {
            for(int profit_idx = 1; profit_idx <= k; ++profit_idx) {
                buy_profit[profit_idx] = max(buy_profit[profit_idx], sell_profit[profit_idx - 1] - p);
                sell_profit[profit_idx] = max(sell_profit[profit_idx], buy_profit[profit_idx] + p);//sell_profit
            }
        }
        
        return sell_profit[k];
    }
    
private:
    int quick_solve(vector<int>& prices) {
        int max_profit = 0;
        for(int i = 1; i < prices.size(); ++i) {
            if(prices[i] > prices[i - 1]) {
                max_profit += prices[i] - prices[i - 1];//if there is a price gap, we will complete one transaction to get profit.//greedy
            }
        }
        return max_profit;
    }
};