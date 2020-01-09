#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        vector<int> profits(n);

        int tmp = prices[0], result = 0, result1 = 0;
        
        for (int i = 1; i < n; ++i) {
            if (tmp > prices[i]) {
                tmp = prices[i];
                profits[i] = result;
                continue;
            }

            if (prices[i] - tmp > result) {
                profits[i] = result = prices[i] - tmp;
            } else {
                profits[i] = result;
            }
        }

        tmp = prices[n-1];
        int max_profit = result;
        for (int i = n - 2; i > 0; --i) {
            if (tmp < prices[i]) {
                tmp = prices[i];
                continue;
            }
            if (tmp - prices[i] > result1) {
                max_profit = max(profits[i-1] + (result1 = tmp - prices[i]), max_profit);
            }
        }
        return max_profit;
    }
};