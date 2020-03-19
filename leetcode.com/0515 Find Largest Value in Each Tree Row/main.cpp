#include <iostream>
#include <queue>
#include <vector>

#include "leetcode.hpp"

using namespace std;

class Solution {
 public:
  vector<int> largestValues(TreeNode *root) {
    vector<int> res;
    if (!root) return res;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      res.push_back(INT32_MIN);
      for (int sz = q.size(); sz > 0; --sz) {
        TreeNode *pn = q.front();
        q.pop();
        if (pn->val > res.back()) res.back() = pn->val;
        if (pn->left) q.push(pn->left);
        if (pn->right) q.push(pn->right);
      }
    }
    return res;
  }
};

template <typename T>
void printArr(const vector<T> &arr) {
  for (const T &t : arr) {
    cout << t << " ";
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  Solution s;
  TreeNode t1(0), t2(1), t3(2);
  t1.left = &t2;
  t1.right = &t3;
  printArr(s.largestValues(&t1));
  return 0;
}
