#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// greedy
class Solution {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> stk;
    int i = 0, j = 0, n = pushed.size();
    while (i < n) {
      stk.push(pushed[i++]);
      while (!stk.empty() && stk.top() == popped[j]) {
        stk.pop();
        ++j;
      }
    }
    return stk.empty();
  }
};
