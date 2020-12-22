#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// ref: [C++/Java/Python] One Pass, Real O(N)
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/discuss/161268/C%2B%2BJavaPython-One-Pass-Real-O(N)

// class Solution {
//  public:
//   int preIndex = 0, posIndex = 0;
//   TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
//     TreeNode* root = new TreeNode(pre[preIndex++]);
//     if (root->val != post[posIndex])
//       root->left = constructFromPrePost(pre, post);
//     if (root->val != post[posIndex])
//       root->right = constructFromPrePost(pre, post);
//     posIndex++;
//     return root;
//   }
// };

class Solution {
 public:
  TreeNode* constructFromPrePost(vector<int> pre, vector<int> post) {
    vector<TreeNode*> s;
    s.push_back(new TreeNode(pre[0]));
    for (int i = 1, j = 0; i < pre.size(); ++i) {
      TreeNode* node = new TreeNode(pre[i]);
      while (s.back()->val == post[j]) s.pop_back(), j++;
      if (s.back()->left == NULL)
        s.back()->left = node;
      else
        s.back()->right = node;
      s.push_back(node);
    }
    return s[0];
  }
};
