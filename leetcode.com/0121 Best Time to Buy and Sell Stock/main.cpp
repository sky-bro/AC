#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        int min_price = prices[0];
        int profit = 0;
        for (int p: prices) {
            if (p > min_price) {
                if (p - min_price > profit)
                    profit = p - min_price;
            }
            else min_price = p;
        }
        return profit;
    }
};