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
    TreeNode* _buildTree(vector<int>& inorder, vector<int>& postorder, int i_left, int i_right, int p_left, int p_right) {
        TreeNode* root =  new TreeNode(postorder[p_right]);
        int idx = i_left;
        for (; idx <= i_right && inorder[idx] != postorder[p_right]; ++idx);
        if (idx - i_left != 0) root->left = _buildTree(inorder, postorder, i_left, idx-1, p_left, p_left + idx - i_left - 1);
        if (i_right - idx != 0) root->right = _buildTree(inorder, postorder, idx+1, i_right, p_right - (i_right - idx), p_right-1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if (n == 0) return nullptr;
        return _buildTree(inorder, postorder, 0, n-1, 0, n-1);
    }
};