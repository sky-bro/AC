#include <iostream>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool inorder(TreeNode* root, TreeNode* &prev) {
        if (root->left && !inorder(root->left, prev)) return false;
        if (prev && root->val <= prev->val) return false;
        prev = root;
        if (root->right && !inorder(root->right, prev)) return false;
        return true;
    }

    bool inorder_reverse(TreeNode* root, TreeNode* &prev) {
        if (root->right && !inorder_reverse(root->right, prev)) return false;
        if (prev && root->val >= prev->val) return false;
        prev = root;
        if (root->left && !inorder_reverse(root->left, prev)) return false;
        return true;
    }
public:
    void recoverTree(TreeNode* root) {
        TreeNode* left = nullptr;
        inorder(root, left);
        TreeNode* right = nullptr;
        inorder_reverse(root, right);
        int tmp = left->val;
        left->val = right->val;
        right->val = tmp;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode n1 = TreeNode(1);
    TreeNode n2 = TreeNode(2);
    TreeNode n3 = TreeNode(3);
    n1.left = &n3;
    n3.right = &n2;
    Solution s;
    s.recoverTree(&n1);
    return 0;
}
