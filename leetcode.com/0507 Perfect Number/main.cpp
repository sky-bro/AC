#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool checkPerfectNumber(int num) {
    if (num <= 1) return false;
    int sum = 1;
    int i = sqrt(num);
    if (i * i == num) sum += i--;
    for (; i > 1; --i) {
      if (num % i == 0) {
        sum += i + num / i;
      }
    }
    return sum == num;
  }
};