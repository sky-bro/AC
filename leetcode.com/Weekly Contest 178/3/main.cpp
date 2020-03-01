#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 private:
  bool dfs(ListNode *head, TreeNode *root, bool fromStart) {
    if (!head) return true;
    if (!root) return false;
    if (head->val != root->val) {
      if (fromStart) {
        if (dfs(head, root->left, true)) return true;
        if (dfs(head, root->right, true)) return true;
        return false;
      } else {
        return false;
      }
    }
    if (dfs(head->next, root->left, false)) return true;
    if (dfs(head->next, root->right, false)) return true;
    if (fromStart) {
      if (dfs(head, root->left, true)) return true;
      if (dfs(head, root->right, true)) return true;
      return false;
    }
    return false;
  }

 public:
  bool isSubPath(ListNode *head, TreeNode *root) {
    return dfs(head, root, true);
  }
};