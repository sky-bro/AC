#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool lemonadeChange(vector<int>& bills) {
    int cnt5 = 0, cnt10 = 0, cnt20 = 0;
    for (int bill : bills) {
      if (bill == 5)
        ++cnt5;
      else if (bill == 10)
        ++cnt10;
      else
        ++cnt20;
      bill -= 5;
      int c20 = min(bill / 20, cnt20);
      cnt20 -= c20;
      bill -= 20 * c20;
      int c10 = min(bill / 10, cnt10);
      cnt10 -= c10;
      bill -= 10 * c10;
      int c5 = min(bill / 5, cnt5);
      cnt5 -= c5;
      bill -= 5 * c5;
      if (bill) return false;
    }
    return true;
  }
};
