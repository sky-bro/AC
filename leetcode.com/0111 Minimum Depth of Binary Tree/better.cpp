#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int min_len;
    void DFS(TreeNode* node, int len)
    {
        if(!node->left && !node->right) {
            if(min_len == -1 || len < min_len) {
                min_len = len;
            }
            return;
        }
        if(node->left) {
            DFS(node->left, len+1);
        }
        if(node->right) {
            DFS(node->right, len+1);
        }
    }
public:
    int minDepth(TreeNode* root) 
    {
        if(!root) return 0;
        min_len = -1;
        DFS(root, 1);
        return min_len;
    }
};