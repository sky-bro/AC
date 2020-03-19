#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<bool> visited(n);
    vector<int> res(n, -1);
    stack<pair<int, int>> stk;
    for (int j = 0; j < 2; ++j) {
      for (int i = 0; i < n; ++i) {
        while (!stk.empty() && stk.top().first < nums[i]) {
          int idx = stk.top().second;
          if (!visited[idx]) {
            visited[idx] = true;
            res[idx] = nums[i];
          }
          stk.pop();
        }
        stk.emplace(nums[i], i);
      }
    }
    return res;
  }
};