#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// use stack
class Solution {
 private:
  vector<int> res;

 public:
  vector<int> lexicalOrder(int n) {
    res.clear();
    stack<int> stk;
    for (int i = 9; i > 0; --i) {
      if (i <= n) stk.push(i);
    }

    while (!stk.empty()) {
      int top = stk.top();
      stk.pop();
      res.push_back(top);
      top *= 10;
      for (int i = 9; i >= 0; --i) {
        if (top + i <= n) stk.push(top + i);
      }
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int n = 30;
  s.lexicalOrder(n);
  return 0;
}
