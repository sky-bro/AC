#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int thirdMax(vector<int>& nums) {
    long long a = INT64_MIN, b = INT64_MIN, c = INT64_MIN;
    for (int num : nums) {
      if (num == a || num == b || num == c) continue;
      if (num > a) {
        c = b;
        b = a;
        a = num;
      } else if (num > b) {
        c = b;
        b = num;
      } else if (num > c) {
        c = num;
      }
    }
    return c == INT64_MIN ? a : c;
  }
};