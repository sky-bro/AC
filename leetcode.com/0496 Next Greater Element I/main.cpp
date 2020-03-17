#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

// ref: https://en.wikipedia.org/wiki/Stack-sortable_permutation
// ref:
// https://leetcode.com/problems/next-greater-element-i/discuss/97613/C%2B%2B-stack-%2B-unordered_map
class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> stk;
    unordered_map<int, int> m;
    for (int num : nums2) {
      while (!stk.empty() && stk.top() < num) {
        m[stk.top()] = num;
        stk.pop();
      }
      stk.push(num);
    }
    vector<int> res;
    for (int num : nums1) res.push_back(m.count(num) ? m[num] : -1);
    return res;
  }
};