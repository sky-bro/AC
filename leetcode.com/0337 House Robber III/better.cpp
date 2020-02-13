#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    pair<int, int> help(TreeNode* root) {
        if(!root) return {0, 0};
        auto left = help(root->left);
        auto right = help(root->right);
        int candi[4] = {left.first + right.first, left.second + right.first, left.first + right.second, left.second + right.second };
        int *maxelement=max_element(candi,candi+4);
        return {root->val + left.second + right.second , *maxelement};
    }
    
    int rob(TreeNode* root) {
        auto candi = help(root);
        return max(candi.first, candi.second);
    }
};