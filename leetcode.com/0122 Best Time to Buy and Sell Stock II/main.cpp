#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), profit = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (prices[i] >= prices[i+1]) continue;
            for (int j = i + 1; j < n; ++j) {
                if (prices[j] < prices[j-1]) {
                    profit += prices[j-1] - prices[i];
                    i = j - 1;
                    break;
                } else if (j == n - 1) {
                    profit += prices[j] - prices[i];
                    i = j;
                }
            }
        }
        return profit;
    }
};