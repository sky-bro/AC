#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// level traversal
class Solution {
 public:
  bool isCompleteTree(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    bool last = false;
    while (!q.empty()) {
      for (int sz = q.size(); sz; --sz) {
        auto p = q.front();
        q.pop();
        if (p->left) {
          if (last) return false;
          q.push(p->left);
        } else {
          last = true;
        }
        if (p->right) {
          if (last) return false;
          q.push(p->right);
        } else {
          last = true;
        }
      }
    }
    return true;  // full binary tree
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  TreeNode t6(6), t5(5), t4(4), t3(3, &t6, nullptr), t2(2, &t4, &t5),
      t1(1, &t2, &t3);
  cout << s.isCompleteTree(&t1) << endl;
  return 0;
}
