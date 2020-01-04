#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return vector<vector<int>> {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {   int count = q.size();
            vector<int> temp;
         
            while(count--)
            {
                TreeNode *curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            
         res.push_back(temp);
        }
        
    return res;
    }
};