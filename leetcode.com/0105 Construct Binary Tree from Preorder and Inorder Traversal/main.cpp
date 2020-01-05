#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int p_left, int p_right, int i_left, int i_right) {
        TreeNode* root = new TreeNode(preorder[p_left]);
        if (p_left == p_right) return root;

        int idx = i_left;
        for (; idx <= i_right && inorder[idx] != preorder[p_left]; ++idx);
        if (idx - i_left) root->left = _buildTree(preorder, inorder, p_left+1, p_left+idx-i_left, i_left, idx-1);
        if (i_right-idx) root->right = _buildTree(preorder, inorder, p_left+idx-i_left+1, p_right, idx+1, i_right);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if (n == 0) return nullptr;
        return _buildTree(preorder, inorder, 0, n-1, 0, n-1);
    }
};