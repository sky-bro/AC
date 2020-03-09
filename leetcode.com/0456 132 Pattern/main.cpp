#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// ref:
// https://leetcode.com/problems/132-pattern/discuss/166953/Easy-and-concise-C%2B%2B-solution-using-a-stack-with-explanation-VERY-EASY-to-understand
class Solution {
 public:
  bool find132pattern(vector<int>& nums) {
    stack<int> stk;
    int prev = INT32_MIN;
    for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
      while (!stk.empty() && stk.top() < *it) {
        if (prev > stk.top()) return true;
        prev = stk.top();
        stk.pop();
      }
      stk.push(*it);
    }
    return !stk.empty() && prev > stk.top();
  }
};