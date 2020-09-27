#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minOperationsMaxProfit(vector<int>& customers, int boardingCost,
                             int runningCost) {
    int i = 0, n = customers.size();
    vector<int> bucket(4);
    int max_profit = INT32_MIN, min_operation = 0, cur_profit = 0;
    int waiting_num = 0;
    while (i < n || waiting_num) {
      if (i < n) waiting_num += customers[i];
      int board_num = min(4, waiting_num);
      cur_profit += board_num * boardingCost - runningCost;
      waiting_num -= board_num;
      if (max_profit < cur_profit) {
        max_profit = cur_profit;
        min_operation = i + 1;
      }
      ++i;
    }
    return max_profit < 0 ? -1 : min_operation;
  }
};
