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
    int ans{0};
    
    void number(TreeNode* root, int currentSum)
    {
        currentSum += root -> val;
        
        if (root -> left != nullptr)
            number(root -> left, currentSum * 10);
        
        if (root -> right != nullptr)
            number(root -> right, currentSum * 10);
        
        if (root -> left == nullptr && root -> right == nullptr)
            ans += currentSum;
    }
    
    int sumNumbers(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        number(root, 0);
        
        return ans;
    }
};