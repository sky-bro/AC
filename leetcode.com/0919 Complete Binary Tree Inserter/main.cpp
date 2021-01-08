#include <iostream>
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

class CBTInserter {
 private:
  vector<TreeNode *> tree;
  // left: i*2 + 1
  // right: i*2 + 2
 public:
  CBTInserter(TreeNode *root) {
    tree.push_back(root);
    for (int i = 0; i < tree.size(); ++i) {
      if (tree[i]->left) tree.push_back(tree[i]->left);
      if (tree[i]->right) tree.push_back(tree[i]->right);
    }
  }

  int insert(int v) {
    tree.emplace_back(new TreeNode(v));
    int n = tree.size();
    if (n & 1) {  // right
      tree[(n - 2) / 2]->right = tree.back();
    } else {
      tree[(n - 2) / 2]->left = tree.back();
    }
    return tree[(n - 2) / 2]->val;
  }

  TreeNode *get_root() { return tree[0]; }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
