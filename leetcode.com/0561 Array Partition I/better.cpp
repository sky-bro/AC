#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// bucket sort
class Solution {
 public:
  int arrayPairSum(vector<int>& nums) {
    vector<int> counter(20001, 0);

    for (int i = 0; i < nums.size(); i++) {
      counter[10000 + nums[i]]++;
    }

    int sum = 0;
    int pick = 0;
    for (int i = 0; i < counter.size(); i++) {
      int p = counter[i];
      if (p > 0) {
        for (int j = 0; j < p; j++) {
          pick++;
          if (pick % 2) sum += (i - 10000);
        }
      }
    }

    return sum;
  }
};