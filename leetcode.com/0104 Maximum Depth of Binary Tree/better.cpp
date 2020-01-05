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
public:
    int maxDepth(TreeNode* root) {
        
        if(!root)
            return 0;
        
        int left = maxDepth(root->left) + 1;
        int right = maxDepth(root->right) + 1;
        return max(left,right);
    }
};