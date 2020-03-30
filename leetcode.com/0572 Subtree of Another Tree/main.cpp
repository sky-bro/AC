// ref: Python, Straightforward with Explanation (O(ST) and O(S+T) approaches)
// https://leetcode.com/problems/subtree-of-another-tree/discuss/102741/Python-Straightforward-with-Explanation-(O(ST)-and-O(S%2BT)-approaches)
// ref: Java Solution, tree traversal
// https://leetcode.com/problems/subtree-of-another-tree/discuss/102724/Java-Solution-tree-traversal
#include <iostream>
#include <vector>

#include "leetcode.hpp"

using namespace std;

class Solution {
 private:
  bool isSame(TreeNode* s, TreeNode* t) {
    if (!s && !t) return true;
    if (!s || !t) return false;
    if (s->val != t->val) return false;
    return isSame(s->left, t->left) && isSame(s->right, t->right);
  }

 public:
  bool isSubtree(TreeNode* s, TreeNode* t) {
    if (!s) return false;
    if (isSame(s, t)) return true;
    return isSubtree(s->left, t) || isSubtree(s->right, t);
  }
};